#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator, class Predicate>
    ForwardIterator seq::remove_if(ForwardIterator first, ForwardIterator last, Predicate pred){
    return std::remove_if(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
