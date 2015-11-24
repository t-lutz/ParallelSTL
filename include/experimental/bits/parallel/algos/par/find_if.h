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
    InputIterator parallel_execution_policy::find_if(InputIterator first, InputIterator last,
                                                     Predicate pred) const 
  {
    return detail::diffract_gather_compare(
        first, last,
        std::find_if<InputIterator, Predicate>,
        [&](const InputIterator &a, const InputIterator &end_a, 
            const InputIterator &b, const InputIterator &/*unused*/){
          // The comparison operator returns the first non-end iterator
          return distance(first, a) < distance(first, b) && a != end_a ? a : b;
        },
        pred);

  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
