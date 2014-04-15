#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class RandomAccessIterator>
    void sequential_execution_policy::nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                          RandomAccessIterator last) const {
    std::nth_element(first, nth, last);
  }


  template<class RandomAccessIterator, class Compare>
    void sequential_execution_policy::nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                          RandomAccessIterator last, Compare comp) const {
    std::nth_element(first, nth, last, comp);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
