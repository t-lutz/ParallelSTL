#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Predicate>
    bool parallel_execution_policy::any_of(InputIterator first, InputIterator last, Predicate pred) const
  {
    return detail::diffract_gather(first, last, 
                                   std::any_of<InputIterator, Predicate>,
                                   std::bit_or<bool>(),
                                   false);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
