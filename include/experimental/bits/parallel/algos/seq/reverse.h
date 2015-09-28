#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class BidirectionalIterator>
    void sequential_execution_policy::reverse(BidirectionalIterator first, BidirectionalIterator last) const {
    std::reverse(first, last);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
