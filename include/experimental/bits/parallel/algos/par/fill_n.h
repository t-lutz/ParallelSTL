#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class OutputIterator, class Size, class T>
    void parallel_execution_policy::fill_n(OutputIterator first, Size n, const T& value) const {
      static const std::function<void(OutputIterator, OutputIterator, const T&)> __fill =
              (void(*)(OutputIterator, OutputIterator, const T&))&fill<OutputIterator, T>;
      detail::diffract(first, first + count, std::fill<OutputIterator, T>, value);
      // return std::max(first, first + count);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
