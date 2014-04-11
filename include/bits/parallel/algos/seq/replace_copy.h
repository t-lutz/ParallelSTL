#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class OutputIterator, class T>
    OutputIterator
      seq::replace_copy(InputIterator first, InputIterator last,
                        OutputIterator result,
                        const T& old_value, const T& new_value){
    return std::replace_copy(first, last, result, old_value, new_value);
  }

} // namespace policy
} // namespace parallel
} // namespace std
