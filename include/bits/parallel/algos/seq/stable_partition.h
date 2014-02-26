#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class BidirectionalIterator, class Predicate>
    BidirectionalIterator
      seq::stable_partition(BidirectionalIterator first,
                            BidirectionalIterator last, Predicate pred){
    return std::stable_partition(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
