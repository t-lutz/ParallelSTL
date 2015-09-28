#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class OutputIterator, class Predicate>
    OutputIterator
      sequential_execution_policy::remove_copy_if(InputIterator first, InputIterator last,
                          OutputIterator result, Predicate pred) const {
    return std::remove_copy_if(first, last, result, pred);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
