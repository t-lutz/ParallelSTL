#include <thread>
#include <vector>
#include <algorithm>

#include <iostream>

/*
 * Utility functions to divide a range into chunks (one chunk per thread, as defined
 * by std::thread::hardware_concurrency) and spawn a thread per chunk, executing 
 * a given function on the sub-range. 
 *
 * The diffract_gather function also combine the return values of each sub-range using
 * a collapse function.
 *
 * This is a really dumb approach, it doesn't have a pool thread per-se, it just 
 * keeps spawning threads. This is just a draft implementation for quick experiments.
 */

namespace std {
namespace experimental {
namespace parallel {
namespace detail {

template<class Iterator, class Functor, typename ... Args>
inline void diffract(Iterator first, Iterator last, Functor f, Args ... args){
  // segment the iteration space: if there is not enough elements we do not
  // divide the iteration space.
  const unsigned int segment_size =
    distance(first, last) > (thread::hardware_concurrency()) ?
    distance(first, last) / (thread::hardware_concurrency()) :
    segment_size; // is not even one per proc, we don't divide

  // number of segments
  const unsigned pool_size = distance(first, last) / segment_size;

  // thread pool
  vector<thread> pool;
  pool.reserve(pool_size);

  // divide the iteration space and delegate to threads.
  Iterator it = first;
  for(unsigned i = 0; i < pool_size; ++i, it += segment_size){
    // the last chunk takes care of the rounding error
    const Iterator end = (i < pool_size - 1 ? it + segment_size : last);
    // create the dedicated thread and push it in the pool
    pool.emplace_back(thread{f, it, end, args...});
  }

  // wait for the pool to finish
  for(auto &t : pool) t.join();
}

// it looks like the variadic capture in lambdas is still not working with gcc 4.8,
// the following is a specialized functor used in place of a lambda in the
// thread creation for diffract_gather
template<typename T, typename Function, typename Iterator, typename ... Args>
void diffract_functor(T & result, Function f, Iterator begin, Iterator end, Args ...args) {
    result = f(begin, end, args...);
}

template<class Iterator, class Functor, class BinaryGather, typename ... Args>
inline typename iterator_traits<Iterator>::value_type
diffract_gather(Iterator first, Iterator last, Functor f, BinaryGather g, Args ... args){
  typedef typename iterator_traits<Iterator>::value_type T;

  // segment the iteration space: if there is not enough elements we do not
  // divide the iteration space.
  const unsigned int segment_size =
    distance(first, last) > (thread::hardware_concurrency()) ?
    distance(first, last) / (thread::hardware_concurrency()) :
    segment_size; // is not even one per proc, we don't divide

  // number of segments
  const unsigned pool_size = distance(first, last) / segment_size;

  // thread pool
  vector<thread> pool;
  pool.reserve(pool_size);

  // temporary space for accumulators
  vector<T> gather(pool_size); 

  // divide the iteration space and delegate to threads.
  Iterator it = first;
  for(unsigned i = 0; i < pool_size; ++i, it += segment_size){
    // the last chunk takes care of the rounding error
    const Iterator end = (i < pool_size - 1 ? it + segment_size : last);
    auto fct = &diffract_functor<T, Functor, Iterator, Args...>;
    pool.emplace_back(thread{fct, std::ref(gather[i]), f, it, end, args...});
  }

  // wait for the pool to finish
  for(auto &t : pool) t.join();

  // apply the collapse function and return
  return accumulate(gather.begin()+1, gather.end(), *gather.begin(), g);
}

} // namespace detail
} // namespace parallel
} // namespace experimental
} // namespace std

