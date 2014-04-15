#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator, class Predicate>
    typename iterator_traits<InputIterator>::difference_type
      sequential_execution_policy::count_if(InputIterator first, InputIterator last, Predicate pred) const {
    return std::count_if(first, last, pred);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
