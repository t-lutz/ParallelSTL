#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class Predicate>
    bool seq::is_partitioned(InputIterator first, InputIterator last, Predicate pred){
    return std::is_partitioned(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
