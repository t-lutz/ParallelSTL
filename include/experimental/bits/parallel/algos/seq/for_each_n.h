#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator, class Size, class Function>
    InputIterator sequential_execution_policy::for_each_n(InputIterator first, Size n,
                                                          Function f) const 
  {
    if(n < 0)
      return first;
    auto end = first;
    advance(end, n);
    std::for_each(first, end, f);
    return end;
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
