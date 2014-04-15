#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class OutputIterator,
           class UnaryOperation>
    OutputIterator sequential_execution_policy::transform(InputIterator first, InputIterator last,
                                  OutputIterator result, UnaryOperation op) const {
    return std::transform(first, last, result, op);
  }


  template<class InputIterator1, class InputIterator2, class OutputIterator,
           class BinaryOperation>
    OutputIterator
      sequential_execution_policy::transform(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, OutputIterator result,
                     BinaryOperation binary_op) const {
    return std::transform(first1, last1, first2, result, binary_op);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
