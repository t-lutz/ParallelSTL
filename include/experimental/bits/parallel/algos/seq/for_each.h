#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class Function>
  Function seq::for_each(InputIterator first, InputIterator last, Function f){ 
    return std::for_each(first, last, f);
  }

} // namespace policy
} // namespace parallel
} // namespace std
