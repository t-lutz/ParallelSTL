#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class OutputIterator, class Size, class Generator>
    OutputIterator sequential_execution_policy::generate_n(OutputIterator first, Size n, Generator gen) const {
    return std::generate_n(first, n, gen);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
