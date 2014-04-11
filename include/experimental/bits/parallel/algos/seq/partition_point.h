#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator, class Predicate>
    ForwardIterator sequential_execution_policy::partition_point(ForwardIterator first,
                                         ForwardIterator last,
                                         Predicate pred){
    return std::partition_point(first, last, pred);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
