#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator, class Predicate, class T>
    void parallel_execution_policy::replace_if(ForwardIterator first, ForwardIterator last,
                                               Predicate pred, const T& new_value) const {
    detail::diffract(first, last, std::replace_if<ForwardIterator, Predicate, T>, pred, new_value);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
