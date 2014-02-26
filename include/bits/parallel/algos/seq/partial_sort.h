#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class RandomAccessIterator>
    void seq::partial_sort(RandomAccessIterator first,
                           RandomAccessIterator middle,
                           RandomAccessIterator last){
    std::partial_sort(first, middle, last);
  }

  template<class RandomAccessIterator, class Compare>
    void seq::partial_sort(RandomAccessIterator first,
                           RandomAccessIterator middle,
                           RandomAccessIterator last,
                           Compare comp){
    std::partial_sort(first, middle, last, comp);
  }

} // namespace policy
} // namespace parallel
} // namespace std
