#include <thread>
#include <vector>
#include <algorithm>

namespace std {
namespace detail {

template<class Iterator, class Functor, typename ... Args>
inline void diffract(Iterator first, Iterator last, Functor f, Args ... args){
  // segment the iteration space: if there is not enough elements we do not
  // divide the iteration space.
  const unsigned int segment_size =
    distance(first, last) > (thread::hardware_concurrency()) ?
    distance(first, last) / (thread::hardware_concurrency()) :
    segment_size; // is not even one per proc, we don't divide

  // thread pool
  vector<thread> pool;
  pool.reserve((distance(first, last) / segment_size) + 1);

  // divide the iteration space and delegate to threads.
  Iterator it = first;
  for(; it < last - segment_size; it += segment_size){
    pool.emplace_back(thread(f, it, it + segment_size, args...));
  }
  pool.emplace_back(thread(f, it, last, args...));

  // wait for the pool to finish
  for(auto &t : pool) t.join();
}

// This implementation is not functional yet
template<class Iterator, class Functor, class BinaryGather, typename ... Args>
inline typename iterator_traits<Iterator>::value_type
diffract_gather(Iterator first, Iterator last, Functor f, BinaryGather g, Args ... args){
   // segment the iteration space: if there is not enough elements we do not
  // divide the iteration space.
  const unsigned int segment_size =
    distance(first, last) > (thread::hardware_concurrency()) ?
    distance(first, last) / (thread::hardware_concurrency()) :
    segment_size; // is not even one per proc, we don't divide

  // thread pool
  vector<thread> pool;
  pool.reserve((distance(first, last) / segment_size) + 1);

  // temporary space for accumulators
  // TODO: fixme: compute the exact size
  vector<typename iterator_traits<Iterator>::value_type> gather((distance(first, last) / segment_size) + 1); // The size should be exact

  // divide the iteration space and delegate to threads.
  Iterator it = first;
  size_t counter = 0;
  for(; it < last - segment_size; it += segment_size, ++counter){
    pool.emplace_back(thread(
      //[&, args...] mutable {
      //  gather[counter] = f(it, it + segment_size, args...);
      //}
    ));
  }
  pool.emplace_back(std::thread(
    //[&, args...] mutable {
    //  gather[counter] = f(it, last, args...);
    //}
  ));

  // wait for the pool to finish
  for(auto &t : pool) t.join();

  // apply the collapse function and return
  return std::accumulate(gather.begin()+1, gather.end(), *gather.begin(), g);
}
}
}

