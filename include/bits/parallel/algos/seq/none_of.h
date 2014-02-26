#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class Predicate>
    bool seq::none_of(InputIterator first, InputIterator last, Predicate pred){
    return std::none_of(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
