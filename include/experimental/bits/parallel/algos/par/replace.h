#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator, class T>
    void parallel_execution_policy::replace(ForwardIterator first, ForwardIterator last,
                      const T& old_value, const T& new_value) const {
      detail::diffract(first, last, std::replace<ForwardIterator, T>, old_value, new_value);
    }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
