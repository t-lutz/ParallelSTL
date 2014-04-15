#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator1, class InputIterator2>
    bool sequential_execution_policy::equal(InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2) const {
    return std::equal(first1, last1, first2);
  }


  template<class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool sequential_execution_policy::equal(InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2, BinaryPredicate pred) const {
    return std::equal(first1, last1, first2, pred);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
