#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class BidirectionalIterator, class OutputIterator>
    OutputIterator
      seq::reverse_copy(BidirectionalIterator first,
                        BidirectionalIterator last, OutputIterator result){
    return std::reverse_copy(first, last, result);
  }

} // namespace policy
} // namespace parallel
} // namespace std
