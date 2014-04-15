#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Size, class OutputIterator>
    OutputIterator sequential_execution_policy::copy_n(InputIterator first, Size n,
                                                       OutputIterator result) const {
    return std::copy_n(first, n, result);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
