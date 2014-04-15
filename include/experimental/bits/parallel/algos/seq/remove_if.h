#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator, class Predicate>
    ForwardIterator sequential_execution_policy::remove_if(ForwardIterator first, 
                                                           ForwardIterator last, 
                                                           Predicate pred) const {
    return std::remove_if(first, last, pred);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
