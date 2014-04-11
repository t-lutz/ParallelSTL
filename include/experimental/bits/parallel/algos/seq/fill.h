#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator, class T>
    void seq::fill(ForwardIterator first, ForwardIterator last, const T& value){
    std::fill(first, last, value);
  }

} // namespace policy
} // namespace parallel
} // namespace std
