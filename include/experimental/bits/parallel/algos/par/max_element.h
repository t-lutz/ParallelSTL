#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator>
    ForwardIterator parallel_execution_policy::max_element(ForwardIterator first, 
                                                           ForwardIterator last) const 
  {
    return detail::diffract_gather(first, last,
                                   max_element<ForwardIterator>,
                                   std::max<ForwardIterator>());
  }


  template<class ForwardIterator, class Compare>
    ForwardIterator parallel_execution_policy::max_element(ForwardIterator first, 
                                                           ForwardIterator last,
                                                           Compare comp) const {
    return detail::diffract_gather(first, last,
                                   max_element<ForwardIterator, Compare>,
                                   std::max<ForwardIterator>(),
                                   comp);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
