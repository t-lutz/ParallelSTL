#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator>
    ForwardIterator seq::unique(ForwardIterator first, ForwardIterator last){
    return std::unique(first, last);
  }


  template<class ForwardIterator, typename BinaryPredicate>
    ForwardIterator seq::unique(ForwardIterator first, ForwardIterator last,
                           BinaryPredicate pred){
    return std::unique(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
