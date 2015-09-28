#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator>
    ForwardIterator parallel_execution_policy::is_heap_until(ForwardIterator first, ForwardIterator last) const 
  {
    return detail::diffract_gather(first, last, 
                                   std::is_heap_until<ForwardIterator>,
                                   std::bit_and<bool>());

  }

  template<class ForwardIterator, class Compare>
    ForwardIterator parallel_execution_policy::is_heap_until(ForwardIterator first, ForwardIterator last,
                                                               Compare comp) const
  {
    return detail::diffract_gather(first, last, 
                                   std::is_heap_until<ForwardIterator, Compare>,
                                   std::bit_and<bool>(),
                                   comp);

  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
