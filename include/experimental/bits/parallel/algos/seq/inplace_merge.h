#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class BidirectionalIterator>
    void sequential_execution_policy::inplace_merge(BidirectionalIterator first,
                            BidirectionalIterator middle,
                            BidirectionalIterator last){
    std::inplace_merge(first, middle, last);
  }


  template<class BidirectionalIterator,
           class Compare>
    void sequential_execution_policy::inplace_merge(BidirectionalIterator first,
                            BidirectionalIterator middle,
                            BidirectionalIterator last, Compare comp){
    std::inplace_merge(first, middle, last, comp);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
