#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator, class T>
    void sequential_execution_policy::fill(ForwardIterator first, ForwardIterator last, const T& value){
    std::fill(first, last, value);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
