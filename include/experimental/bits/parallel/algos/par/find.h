#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class T>
    InputIterator parallel_execution_policy::find(InputIterator first, InputIterator last,
                       const T& value) const
  {
    return detail::diffract_gather(first, last,
                                   std::find<InputIterator, T>,
                                   std::min<InputIterator>(),
                                   value);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
