#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class BidirectionalIterator, class Predicate>
    BidirectionalIterator
      sequential_execution_policy::stable_partition(BidirectionalIterator first,
                            BidirectionalIterator last, Predicate pred) const {
    return std::stable_partition(first, last, pred);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
