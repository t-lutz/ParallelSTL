#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class OutputIterator, class Predicate, class T>
    OutputIterator
      seq::replace_copy_if(InputIterator first, InputIterator last,
                           OutputIterator result, Predicate pred,
                           const T& new_value){
    return std::replace_copy_if(first, last, result, pred, new_value);
  }

} // namespace policy
} // namespace parallel
} // namespace std
