#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator, class T>
    void sequential_execution_policy::replace(ForwardIterator first, ForwardIterator last,
                      const T& old_value, const T& new_value) const {
    return std::replace(first, last, old_value, new_value);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
