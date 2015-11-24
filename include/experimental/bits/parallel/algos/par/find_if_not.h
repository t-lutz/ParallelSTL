#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class Predicate>
    InputIterator parallel_execution_policy::find_if_not(InputIterator first, InputIterator last,
                              Predicate pred) const
  {
    return parallel_execution_policy::find_if(first, last, not1(pred));
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
