#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator, class T>
    ForwardIterator sequential_execution_policy::remove(ForwardIterator first, 
                                                        ForwardIterator last, 
                                                        const T& value) const {
    return std::remove(first, last, value);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
