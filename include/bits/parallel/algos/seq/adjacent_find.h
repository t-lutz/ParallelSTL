#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator>
    ForwardIterator seq::adjacent_find(ForwardIterator first, ForwardIterator last){
    return std::adjacent_find(first, last);
  }


  template<class ForwardIterator, class BinaryPredicate>
    ForwardIterator seq::adjacent_find(ForwardIterator first, ForwardIterator last,
                                  BinaryPredicate pred){
    return std::adjacent_find(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
