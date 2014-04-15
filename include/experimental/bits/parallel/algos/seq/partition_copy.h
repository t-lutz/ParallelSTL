#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class OutputIterator1,
           class OutputIterator2, class Predicate>
  pair<OutputIterator1, OutputIterator2>
  sequential_execution_policy::partition_copy(InputIterator first, InputIterator last,
                      OutputIterator1 out_true, OutputIterator2 out_false,
                      Predicate pred) const {
    return partition_copy(first, last, out_true, out_false, pred);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
