#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class OutputIterator, class T>
    OutputIterator
      sequential_execution_policy::remove_copy(InputIterator first, InputIterator last,
                  OutputIterator result, const T& value) const {
    return std::remove_copy(first, last, result, value);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
