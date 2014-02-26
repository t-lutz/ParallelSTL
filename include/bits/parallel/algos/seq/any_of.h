#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class Predicate>
    bool seq::any_of(InputIterator first, InputIterator last, Predicate pred){
    return std::any_of(first, last, pred);
  }


} // namespace policy
} // namespace parallel
} // namespace std
