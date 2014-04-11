#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator, class T>
    void seq::replace(ForwardIterator first, ForwardIterator last,
                      const T& old_value, const T& new_value){
    return std::replace(first, last, old_value, new_value);
  }

} // namespace policy
} // namespace parallel
} // namespace std
