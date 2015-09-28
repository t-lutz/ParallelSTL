#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator>
    ForwardIterator sequential_execution_policy::unique(ForwardIterator first, ForwardIterator last) const {
    return std::unique(first, last);
  }


  template<class ForwardIterator, typename BinaryPredicate>
    ForwardIterator sequential_execution_policy::unique(ForwardIterator first, ForwardIterator last,
                           BinaryPredicate pred) const {
    return std::unique(first, last, pred);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
