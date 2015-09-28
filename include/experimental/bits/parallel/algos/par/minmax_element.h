#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIt>
    pair<ForwardIt, ForwardIt>
      parallel_execution_policy::minmax_element(ForwardIt first, ForwardIt last) const 
  {
    return this->minmax_element(first, last, std::less<typename iterator_traits<ForwardIt>::value_type>());
  }

  template<class ForwardIt, class Compare>
    pair<ForwardIt, ForwardIt>
      parallel_execution_policy::minmax_element(ForwardIt first, ForwardIt last, 
                                                Compare comp) const 
  {
    return detail::diffract_gather(first, last,
                                   std::minmax_element<ForwardIt, Compare>,
                                   [](const pair<ForwardIt,ForwardIt> &a, const pair<ForwardIt,ForwardIt> &b)
                                     -> pair<ForwardIt,ForwardIt> 
                                   {
                                     return make_pair(min(a.first, b.first), max(a.second, b.second));
                                   },
                                   comp);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
