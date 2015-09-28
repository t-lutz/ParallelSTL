#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator, class T>
    void sequential_execution_policy::fill(ForwardIterator first, ForwardIterator last, const T& value) const {
    std::fill(first, last, value);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
