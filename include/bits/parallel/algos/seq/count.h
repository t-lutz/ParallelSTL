#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class EqualityComparable>
    typename iterator_traits<InputIterator>::difference_type
      seq::count(InputIterator first, InputIterator last, const EqualityComparable &value){
    return std::count(first, last, value);
  }

} // namespace policy
} // namespace parallel
} // namespace std
