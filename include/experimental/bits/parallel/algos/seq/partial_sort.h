#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class RandomAccessIterator>
    void sequential_execution_policy::partial_sort(RandomAccessIterator first,
                           RandomAccessIterator middle,
                           RandomAccessIterator last){
    std::partial_sort(first, middle, last);
  }

  template<class RandomAccessIterator, class Compare>
    void sequential_execution_policy::partial_sort(RandomAccessIterator first,
                           RandomAccessIterator middle,
                           RandomAccessIterator last,
                           Compare comp){
    std::partial_sort(first, middle, last, comp);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
