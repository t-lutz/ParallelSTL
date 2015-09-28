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
    typename iterator_traits<InputIterator>::difference_type
      parallel_execution_policy::count_if(InputIterator first, InputIterator last, Predicate pred) const 
  {
    return detail::diffract_gather(first, last,
                                   std::count_if<InputIterator, Predicate>,
                                   std::plus<typename iterator_traits<InputIterator>::difference_type>(),
                                   pred);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
