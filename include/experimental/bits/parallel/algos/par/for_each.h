#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <functional>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Function>
  Function parallel_execution_policy::for_each(InputIterator first, InputIterator last, Function f) const { 
    // function to wrap: we need the full type to avoid ambiguities
    static const std::function<UnaryFunction(InputIterator, InputIterator, UnaryFunction)> __for_each =
        (UnaryFunction(*)(InputIterator, InputIterator, UnaryFunction))&for_each<InputIterator, UnaryFunction>;
  
    //  diffract the range and forward
    detail::diffract(first, last, __for_each, std::move(f));
    // return the function
    return std::move(f);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
