#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class OutputIterator, class Predicate, class T>
    OutputIterator
      sequential_execution_policy::replace_copy_if(InputIterator first, InputIterator last,
                           OutputIterator result, Predicate pred,
                           const T& new_value) const {
    return std::replace_copy_if(first, last, result, pred, new_value);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
