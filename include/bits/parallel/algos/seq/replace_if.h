#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator, class Predicate, class T>
    void seq::replace_if(ForwardIterator first, ForwardIterator last,
                         Predicate pred, const T& new_value){
    return std::replace_if(first, last, pred, new_value);
  }

} // namespace policy
} // namespace parallel
} // namespace std
