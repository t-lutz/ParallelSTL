#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator1, class InputIterator2>
    pair<InputIterator1,InputIterator2>
      sequential_execution_policy::mismatch(InputIterator1 first1, InputIterator1 last1, 
                    InputIterator2 first2) const {
    return std::mismatch(first1, last1, first2);
  }

  template<class InputIterator1, class InputIterator2, class BinaryPredicate>
    pair<InputIterator1,InputIterator2>
      sequential_execution_policy::mismatch(InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2, BinaryPredicate pred) const {
    return std::mismatch(first1, last1, first2, pred);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
