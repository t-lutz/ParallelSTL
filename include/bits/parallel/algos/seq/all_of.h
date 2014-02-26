#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class Predicate>
    bool seq::all_of(InputIterator first, InputIterator last, Predicate pred){
    return std::all_of(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
