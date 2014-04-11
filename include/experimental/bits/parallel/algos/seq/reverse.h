#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class BidirectionalIterator>
    void seq::reverse(BidirectionalIterator first, BidirectionalIterator last){
    std::reverse(first, last);
  }

} // namespace policy
} // namespace parallel
} // namespace std
