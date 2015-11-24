#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class T>
    InputIterator parallel_execution_policy::find(InputIterator first, InputIterator last,
                       const T& value) const
  {
    return detail::diffract_gather_compare(
        first, last,
        std::find<InputIterator, T>,
        [&](const InputIterator &a, const InputIterator &end_a, 
            const InputIterator &b, const InputIterator &/*unused*/){
          // The comparison operator returns the first non-end iterator
          return distance(first, a) < distance(first, b) && a != end_a ? a : b;
        },
        value);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
