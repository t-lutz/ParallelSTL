#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Predicate>
    InputIterator parallel_execution_policy::find_if(InputIterator first, InputIterator last,
                                                     Predicate pred) const 
  {
    return detail::diffract_gather(first, last,
                                   std::find_if<InputIterator, Predicate>,
                                   std::min<InputIterator>(),
                                   pred);

  }

} // namespace parallel
} // namespace experimental
} // namespace std
