#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class BidirectionalIterator, class OutputIterator>
    OutputIterator
      sequential_execution_policy::reverse_copy(BidirectionalIterator first,
                        BidirectionalIterator last, OutputIterator result) const {
    return std::reverse_copy(first, last, result);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
