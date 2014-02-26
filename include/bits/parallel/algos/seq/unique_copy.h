#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class OutputIterator>
    OutputIterator
      seq::unique_copy(InputIterator first, InputIterator last,
                  OutputIterator result){
    return std::unique_copy(first, last, result);
  }


  template<class InputIterator, class OutputIterator, class BinaryPredicate>
    OutputIterator
      seq::unique_copy(InputIterator first, InputIterator last,
                  OutputIterator result, BinaryPredicate pred){
    return std::unique_copy(first, last, result, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
