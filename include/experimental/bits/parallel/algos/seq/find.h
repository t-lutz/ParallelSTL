#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class T>
    InputIterator seq::find(InputIterator first, InputIterator last,
                       const T& value){
    return std::find(first, last, value);
  }

} // namespace policy
} // namespace parallel
} // namespace std
