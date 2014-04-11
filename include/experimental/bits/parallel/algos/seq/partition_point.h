#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator, class Predicate>
    ForwardIterator seq::partition_point(ForwardIterator first,
                                         ForwardIterator last,
                                         Predicate pred){
    return std::partition_point(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
