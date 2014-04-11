#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class Predicate>
    typename iterator_traits<InputIterator>::difference_type
      seq::count_if(InputIterator first, InputIterator last, Predicate pred){
    return std::count_if(first, last, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
