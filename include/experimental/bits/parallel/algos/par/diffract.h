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
 * @param first The beginning of the range.
 * @param end The end of the range.
 * @param partitions The number of partitions
 * @return A vector of iterator pairs for each sub-range. The list is guaranteed to contain at least
 *         one range.
 **/
template<class Iterator>
inline vector<pair<Iterator,Iterator>> split(Iterator first, Iterator last){
  const size_t partitions = min((size_t)thread::hardware_concurrency(), (size_t)distance(first, last));

  vector<pair<Iterator,Iterator>> chunks;
  chunks.reserve(partitions);

  const unsigned segment_size = distance(first, last) / max(partitions, size_t{1}); 
 
  // last element of the previous partition
  Iterator end = first;

  for(unsigned i = 0; i + 1 < partitions; ++i){
    Iterator begin = end;
    advance(end, segment_size);
    chunks.emplace_back(make_pair(begin, end));
  }
  
  // push the last chunk (could be slightly larger because of rounding or empty if first == last)
  chunks.emplace_back(make_pair(end, last));

  return chunks;
}


/**
 * @brief Split a range between two iterators and apply a given function with the given
 *        parameters on each sub-range.
 * @param first Beginning of the range.
 * @param last End of the range.
 * @param f A callable object which can be called with a range and some given parameters.
 * @param args Additional parameters for the callable object.
 */
template<class Iterator, class Functor, typename ... Args>
inline void diffract(Iterator first, Iterator last, const Functor f, Args ... args){
  // divide the range
  const auto subranges = split(first, last);

  // thread pool
  vector<thread> pool;
  pool.reserve(subranges.size());

  // divide the iteration space and delegate to threads.
  for(const auto & range : subranges)
    pool.emplace_back(thread{f, 
                             range.first, range.second, 
                             forward<Args>(args)...});

  // wait for the pool to finish
  for(auto &t : pool) t.join();
}

// it looks like the variadic capture in lambdas is still not working with gcc 4.8,
// the following is a specialized functor used in place of a lambda in the
// thread creation for diffract_gather
template<typename T, typename Function, typename Iterator, typename ... Args>
void diffract_functor(T & result, Function f, Iterator begin, Iterator end, Args ...args) 
{
    result = f(begin, end, std::forward<Args>(args)...);
}

/**
 * @brief Split a range between two iterators and apply a given function with the given
 *        parameters on each sub-range. The return values of the function are combined
 *        using a provided collapse function.
 * @param first Beginning of the range.
 * @param last End of the range.
 * @param f A callable object which can be called with a range and some given parameters.
 * @param g The collapse function. It takes two elements of the return type of f and returns
 *          a single element of this type.
 * @param args Additional parameters for the callable object.
 * @return The result of the collapse reduction of the sub-ranges.
 */
template<class Iterator, class Functor, class BinaryGather, typename ... Args>
inline auto
diffract_gather(Iterator first, Iterator last, const Functor f, BinaryGather g, Args ... args)
  -> typename result_of<Functor(Iterator, Iterator, Args...)>::type
{
  using ret_type = typename result_of<Functor(Iterator, Iterator, Args...)>::type;

  // divide the range
  const auto subranges = split(first, last);

  // thread pool
  vector<thread> pool;
  pool.reserve(subranges.size());

  // temporary space for accumulators
  vector<ret_type> gather(subranges.size()); 

  
  // divide the iteration space and delegate to threads.
  auto fct = diffract_functor<ret_type, Functor, Iterator, Args...>;
  size_t counter = 0;
  for(const auto & range : subranges)
    pool.emplace_back(thread{fct, ref(gather[counter++]), 
                                  f, 
                                  range.first, range.second, 
                                  forward<Args>(args)...});

  // wait for the pool to finish
  for(auto &t : pool) t.join();

  // apply the collapse function and return
  // TODO: this could also be parallel
  return accumulate(gather.begin()+1, gather.end(), *gather.begin(), g);
}

} // namespace detail
} // namespace parallel
} // namespace experimental
} // namespace std

