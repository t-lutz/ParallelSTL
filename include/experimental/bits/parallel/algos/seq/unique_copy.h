#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class OutputIterator>
    OutputIterator
      sequential_execution_policy::unique_copy(InputIterator first, InputIterator last,
                  OutputIterator result) const {
    return std::unique_copy(first, last, result);
  }


  template<class InputIterator, class OutputIterator, class BinaryPredicate>
    OutputIterator
      sequential_execution_policy::unique_copy(InputIterator first, InputIterator last,
                  OutputIterator result, BinaryPredicate pred) const {
    return std::unique_copy(first, last, result, pred);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
