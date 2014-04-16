#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator>
    bool parallel_execution_policy::is_heap(ForwardIterator first, ForwardIterator last) const 
  {
    return detail::diffract_gather(first, last, 
                                   std::is_heap<ForwardIterator>,
                                   std::bit_and<bool>());
  }


  template<class ForwardIterator, class Compare>
    bool parallel_execution_policy::is_heap(ForwardIterator first, ForwardIterator last,
                        Compare comp) const 
  {
    return detail::diffract_gather(first, last, 
                                   std::is_heap<ForwardIterator, Compare>,
                                   std::bit_and<bool>(),
                                   comp);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
