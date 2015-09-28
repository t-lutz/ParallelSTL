#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class OutputIterator, class Size, class T>
    OutputIterator sequential_execution_policy::fill_n(OutputIterator first, Size n, const T& value) const 
  {
    return std::fill_n(first, n, value);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
