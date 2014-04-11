#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Predicate>
    bool sequential_execution_policy::any_of(InputIterator first, InputIterator last, Predicate pred){
    return std::any_of(first, last, pred);
  }


} // namespace parallel
} // namespace experimental
} // namespace std
