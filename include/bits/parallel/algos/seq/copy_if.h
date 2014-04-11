#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class OutputIterator, class Predicate>
    OutputIterator
      seq::copy_if(InputIterator first, InputIterator last,
                   OutputIterator result, Predicate pred){
    return std::copy_if(first, last, result, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
