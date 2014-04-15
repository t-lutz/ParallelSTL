#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Size, class Function>
    Function sequential_execution_policy::for_each_n(InputIterator first, Size n,
                        Function f) const {
    return std::for_each(first, first + n, f);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
