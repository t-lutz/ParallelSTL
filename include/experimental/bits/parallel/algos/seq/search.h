#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 sequential_execution_policy::search(ForwardIterator1 first1, ForwardIterator1 last1,
                                 ForwardIterator2 first2, ForwardIterator2 last2) const {
    return std::search(first1, last1, first2, last2);
  }

  template<class ForwardIterator1, class ForwardIterator2,
           class BinaryPredicate>
    ForwardIterator1 sequential_execution_policy::search(ForwardIterator1 first1, ForwardIterator1 last1,
                                 ForwardIterator2 first2, ForwardIterator2 last2,
                                 BinaryPredicate pred) const {
    return std::search(first1, last1, first2, last2, pred);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
