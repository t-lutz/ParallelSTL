#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class OutputIterator, class T>
    OutputIterator
      seq::remove_copy(InputIterator first, InputIterator last,
                  OutputIterator result, const T& value){
    return std::remove_copy(first, last, result, value);
  }

} // namespace policy
} // namespace parallel
} // namespace std
