#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class RandomAccessIterator>
    RandomAccessIterator
      sequential_execution_policy::partial_sort_copy(InputIterator first, InputIterator last,
                             RandomAccessIterator result_first,
                             RandomAccessIterator result_last) const {
    return std::partial_sort_copy(first, last, result_first, result_last);
  }

  template<class InputIterator, class RandomAccessIterator,
           class Compare>
    RandomAccessIterator
      sequential_execution_policy::partial_sort_copy(InputIterator first, InputIterator last,
                             RandomAccessIterator result_first,
                             RandomAccessIterator result_last,
                             Compare comp) const {
    return std::partial_sort_copy(first, last, result_first, result_last);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
