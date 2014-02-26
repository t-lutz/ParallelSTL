#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator2
      seq::swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1,
                       ForwardIterator1 first2){
    return std::swap_ranges(first1, last1, first2);
  }

} // namespace policy
} // namespace parallel
} // namespace std
