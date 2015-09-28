#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Function>
  void sequential_execution_policy::for_each(InputIterator first, InputIterator last, Function f) const { 
    std::for_each(first, last, f);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
