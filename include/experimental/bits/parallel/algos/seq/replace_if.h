#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator, class Predicate, class T>
    void sequential_execution_policy::replace_if(ForwardIterator first, ForwardIterator last,
                         Predicate pred, const T& new_value) const {
    return std::replace_if(first, last, pred, new_value);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
