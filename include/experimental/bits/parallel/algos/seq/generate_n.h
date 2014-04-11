#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class OutputIterator, class Size, class Generator>
    OutputIterator sequential_execution_policy::generate_n(OutputIterator first, Size n, Generator gen){
    return std::generate_n(first, n, gen);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
