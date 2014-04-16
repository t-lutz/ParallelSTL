#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <functional>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class UnaryFunction>
  UnaryFunction parallel_execution_policy::for_each(InputIterator first, InputIterator last, 
                                                    UnaryFunction f) const 
  { 
    //  diffract the range and forward
    detail::diffract(first, last, std::for_each<InputIterator, UnaryFunction>, std::move(f));
    // return the function
    return std::move(f);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
