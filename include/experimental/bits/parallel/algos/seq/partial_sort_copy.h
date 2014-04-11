#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class RandomAccessIterator>
    RandomAccessIterator
      seq::partial_sort_copy(InputIterator first, InputIterator last,
                             RandomAccessIterator result_first,
                             RandomAccessIterator result_last){
    return std::partial_sort_copy(first, last, result_first, result_last);
  }

  template<class InputIterator, class RandomAccessIterator,
           class Compare>
    RandomAccessIterator
      seq::partial_sort_copy(InputIterator first, InputIterator last,
                             RandomAccessIterator result_first,
                             RandomAccessIterator result_last,
                             Compare comp){
    return std::partial_sort_copy(first, last, result_first, result_last);
  }

} // namespace policy
} // namespace parallel
} // namespace std
