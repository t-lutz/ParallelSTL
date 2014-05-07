#pragma once

#include <thread>
#include <vector>
#include <algorithm>

/*
 * Utility functions to divide a range into chunks (one chunk per thread, as defined
 * by std::thread::hardware_concurrency) and spawn a thread per chunk, executing 
 * a given function on the sub-range. 
 *
 * The diffract_gather function also combine the return values of each sub-range using
 * a collapse function.
 *
 * This is a really dumb approach, it doesn't have a thread pool per-se, it just 
 * keeps spawning threads. This is just a draft implementation for quick experiments.
 */

namespace std {
namespace experimental {
namespace parallel {
namespace detail {

/**
 * @brief Split a range into partitions chunks. The sub-ranges are of equal size, except the
 *        last one which might be slightly larger to account for rounding error.
 *        If first == last or partitions < 2, the split function returns the range [first, last)
 * @concept __Iterator must meet the requirements of InputIterator.
 * @param first The beginning of the range.
 * @param end The end of the range.
 * @return A vector of iterator pairs for each sub-range. The list is guaranteed to contain at least
 *         one range.
 **/
template<class __Iterator> 
#ifdef __enable_concepts
  requires InputIterator<__Iterator>()
#endif
inline auto splitRange(__Iterator __first, __Iterator __last)
  -> vector<pair<__Iterator,__Iterator>>
{
  const size_t __range_size = distance(__first, __last);
  const size_t __partitions = min((size_t)thread::hardware_concurrency(), __range_size);

  vector<pair<__Iterator,__Iterator>> __chunks;
  __chunks.reserve(__partitions);

  const size_t __segment_size = __range_size / max(__partitions, size_t{1}); 
 
  // last element of the previous partition
  __Iterator __end = __first;

  for(unsigned __i = 0; __i + 1 < __partitions; ++__i){
    __Iterator __begin = __end;
    advance(__end, __segment_size);
    __chunks.emplace_back(make_pair(__begin, __end));
  }
  
  // push the last chunk (could be slightly larger because of rounding or empty if first == last)
  __chunks.emplace_back(make_pair(__end, __last));

  return __chunks;
}


/**
 * @brief Split a range between two iterators and apply a given function with the given
 *        parameters on each sub-range.
 * @concept __Iterator must meet the requirements of InputIterator.
 * @concept __Functor must meet the requirements of FunctionObject.
 * @param first Beginning of the range.
 * @param last End of the range.
 * @param f A callable object which can be called with a range and some given parameters.
 * @param args Additional parameters for the callable object.
 */
template<class __Iterator, class __Functor, typename ... __Args>
#ifdef __enable_concepts
  requires InputIterator<__Iterator>() &&
           FunctionObject<__Functor>()
#endif
inline void diffract(__Iterator __first, __Iterator __last, 
                     const __Functor __f, __Args ... __args)
{
  // divide the range
  const auto __subranges = splitRange(__first, __last);

  // thread pool
  vector<thread> __pool;
  __pool.reserve(__subranges.size());

  // divide the iteration space and delegate to threads.
  for(const auto & __range : __subranges)
    __pool.emplace_back(thread{__f, 
                               __range.first, __range.second, 
                               forward<__Args>(__args)...});

  // wait for the pool to finish
  for(auto &__t : __pool) __t.join();
}

// it looks like the variadic capture in lambdas is still not working with gcc 4.8,
// the following is a specialized functor used in place of a lambda in the
// thread creation for diffract_gather
template<typename T, typename Function, typename __Iterator, typename ... __Args>
#ifdef __enable_concepts
  requires InputIterator<__Iterator>() &&
           FunctionObject<__Functor>()
#endif
void diffract_functor(T & __result, Function __f, __Iterator __begin, __Iterator __end, __Args ...__args) 
{
    __result = __f(__begin, __end, std::forward<__Args>(__args)...);
}

/**
 * @brief Split a range between two iterators and apply a given function with the given
 *        parameters on each sub-range. The return values of the function are combined
 *        using a provided collapse function.
 * @concept __Iterator must meet the requirements of InputIterator.
 * @concept __Functor must meet the requirements of FunctionObject.
 * @concept __BinaryGather must meet the requirements of FunctionObject.
 * @concept The return type of the gather function must meet the requirements of DefaultConstructible.
 * @param first Beginning of the range.
 * @param last End of the range.
 * @param f A callable object which can be called with a range and some given parameters.
 * @param g The collapse function. It takes two elements of the return type of f and returns
 *          a single element of this type.
 * @param args Additional parameters for the callable object.
 * @return The result of the collapse reduction of the sub-ranges.
 */
template<class __Iterator, class __Functor, class __BinaryGather, typename ... __Args>
#ifdef __enable_concepts
  requires InputIterator<__Iterator>() &&
           FunctionObject<__Functor>() &&
           FunctionObject<__BinaryGather>() &&
           DefaultConstructible<typename result_of<__Functor(__Iterator, __Iterator, __Args...)>::type>()
#endif
inline auto
diffract_gather(__Iterator __first, __Iterator __last, 
                const __Functor __f, __BinaryGather __g, __Args ... __args)
  -> typename result_of<__Functor(__Iterator, __Iterator, __Args...)>::type
{
  using __Ret_type = typename result_of<__Functor(__Iterator, __Iterator, __Args...)>::type;

  // divide the range
  const auto __subranges = splitRange(__first, __last);

  // thread pool
  vector<thread> __pool;
  __pool.reserve(__subranges.size());

  // temporary space for accumulators
  vector<__Ret_type> __gather(__subranges.size()); 
  
  // divide the iteration space and delegate to threads.
  auto __fct = diffract_functor<__Ret_type, __Functor, __Iterator, __Args...>;
  size_t counter = 0;
  for(const auto & __range : __subranges)
    __pool.emplace_back(thread{__fct, ref(__gather[counter++]), 
                                      __f, 
                                      __range.first, __range.second, 
                                      forward<__Args>(__args)...});

  // wait for the pool to finish
  for(auto &__t : __pool) __t.join();

  // apply the collapse function and return
  // TODO: this could also be parallel
  return accumulate(__gather.begin()+1, __gather.end(), *__gather.begin(), __g);
}

} // namespace detail
} // namespace parallel
} // namespace experimental
} // namespace std

