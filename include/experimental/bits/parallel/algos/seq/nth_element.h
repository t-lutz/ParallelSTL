#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class RandomAccessIterator>
    void seq::nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                          RandomAccessIterator last){
    std::nth_element(first, nth, last);
  }


  template<class RandomAccessIterator, class Compare>
    void seq::nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                          RandomAccessIterator last, Compare comp){
    std::nth_element(first, nth, last, comp);
  }

} // namespace policy
} // namespace parallel
} // namespace std
