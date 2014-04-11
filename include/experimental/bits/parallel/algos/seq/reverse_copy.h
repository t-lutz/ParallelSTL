#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class BidirectionalIterator, class OutputIterator>
    OutputIterator
      sequential_execution_policy::reverse_copy(BidirectionalIterator first,
                        BidirectionalIterator last, OutputIterator result){
    return std::reverse_copy(first, last, result);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
