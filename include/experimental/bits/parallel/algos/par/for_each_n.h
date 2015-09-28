#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class Size, class Function>
    InputIterator parallel_execution_policy::for_each_n(InputIterator first, Size n,
                                                        Function f) const 
  {
    if(n < 0)
      return first;
    auto end = first;
    advance(end, n);
    detail::diffract(first, end, std::for_each<InputIterator, Function>, std::move(f));
    return end;
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
