#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class ForwardIterator>
    InputIterator
      sequential_execution_policy::find_first_of(InputIterator first1, InputIterator last1,
                         ForwardIterator first2, ForwardIterator last2) const {
    return std::find_first_of(first1, last1, first2, last2);
  }


  template<class InputIterator, class ForwardIterator,
           class BinaryPredicate>
    InputIterator
      sequential_execution_policy::find_first_of(InputIterator first1, InputIterator last1,
                         ForwardIterator first2, ForwardIterator last2,
                         BinaryPredicate pred) const {
    return std::find_first_of(first1, last1, first2, last2, pred);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
