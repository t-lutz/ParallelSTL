#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class Predicate>
    InputIterator seq::find_if(InputIterator first, InputIterator last,
                          Predicate pred){
    return std::find_if(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
