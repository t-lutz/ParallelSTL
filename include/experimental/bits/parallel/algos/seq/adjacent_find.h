#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator>
    ForwardIterator sequential_execution_policy::adjacent_find(ForwardIterator first, 
                                                               ForwardIterator last) const{
    return std::adjacent_find(first, last);
  }


  template<class ForwardIterator, class BinaryPredicate>
    ForwardIterator sequential_execution_policy::adjacent_find(ForwardIterator first, ForwardIterator last,
                                  BinaryPredicate pred) const{
    return std::adjacent_find(first, last, pred);
  }

} // namespace parallel
} // namespace experimental
} // namespace std