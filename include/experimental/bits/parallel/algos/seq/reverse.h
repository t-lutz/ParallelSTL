#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class BidirectionalIterator>
    void sequential_execution_policy::reverse(BidirectionalIterator first, BidirectionalIterator last) const {
    std::reverse(first, last);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
