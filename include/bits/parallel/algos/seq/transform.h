#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class OutputIterator,
           class UnaryOperation>
    OutputIterator seq::transform(InputIterator first, InputIterator last,
                                  OutputIterator result, UnaryOperation op){
    return std::transform(first, last, result, op);
  }


  template<class InputIterator1, class InputIterator2, class OutputIterator,
           class BinaryOperation>
    OutputIterator
      seq::transform(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, OutputIterator result,
                     BinaryOperation binary_op){
    return std::transform(first1, last1, first2, result, binary_op);
  }

} // namespace policy
} // namespace parallel
} // namespace std
