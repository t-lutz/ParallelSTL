#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class Predicate>
    bool parallel_execution_policy::none_of(InputIterator first, InputIterator last, Predicate pred) const
  {
    return detail::diffract_gather(first, last, 
                                   std::none_of<InputIterator, Predicate>,
                                   std::bit_and<bool>());
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
