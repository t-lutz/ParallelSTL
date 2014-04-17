#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class OutputIterator, class Size, class T>
    OutputIterator parallel_execution_policy::fill_n(OutputIterator first, Size n, const T& value) const 
  {
      detail::diffract(first, first + count, std::fill<OutputIterator, T>, value);
      return n > 0 ? first + n : first;
  }

} // namespace parallel
} // namespace experimental
} // namespace std
