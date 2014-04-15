#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Size, class Function>
    Function parallel_execution_policy::for_each_n(InputIterator first, Size n,
                                                   Function f) const 
  {
    //  diffract the range and forward
    detail::diffract(first, first + n, std::for_each<InputIterator, Function>, std::move(f));
    // return the function
    return std::move(f);

  }

} // namespace parallel
} // namespace experimental
} // namespace std
