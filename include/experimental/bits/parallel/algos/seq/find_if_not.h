#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Predicate>
    InputIterator sequential_execution_policy::find_if_not(InputIterator first, InputIterator last,
                              Predicate pred){
    return std::find_if_not(first, last, pred);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
