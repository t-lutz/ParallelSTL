#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator, class Generator>
    void parallel_execution_policy::generate(ForwardIterator first, ForwardIterator last, Generator gen) const 
  {
    detail::diffract(first, last, 
                     std::generate<ForwardIterator, Generator>, 
                     std::forward<Generator>(gen));
  }

} // namespace parallel
} // namespace experimental
} // namespace std
