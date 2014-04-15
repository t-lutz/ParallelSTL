#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator>
    ForwardIterator parallel_execution_policy::min_element(ForwardIterator first, 
                                                           ForwardIterator last) const 
  {
    return detail::diffract_gather(first, last,
                                   min_element<ForwardIterator>,
                                   std::min<ForwardIterator>());
  }


  template<class ForwardIterator, class Compare>
    ForwardIterator parallel_execution_policy::min_element(ForwardIterator first, 
                                                           ForwardIterator last,
                                                           Compare comp) const {
    return detail::diffract_gather(first, last,
                                   min_element<ForwardIterator, Compare>,
                                   std::min<ForwardIterator>(),
                                   comp);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
