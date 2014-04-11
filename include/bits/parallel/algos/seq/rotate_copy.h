#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator, class OutputIterator>
    OutputIterator
      seq::rotate_copy(ForwardIterator first, ForwardIterator middle,
                       ForwardIterator last, OutputIterator result){
    return std::rotate_copy(first, middle, last, result);
  }

} // namespace policy
} // namespace parallel
} // namespace std
