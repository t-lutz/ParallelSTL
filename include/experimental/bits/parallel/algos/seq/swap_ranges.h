#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator1, class ForwardIterator2>
    ForwardIterator2
      sequential_execution_policy::swap_ranges(ForwardIterator1 first1,
                                               ForwardIterator1 last1,
                                               ForwardIterator2 first2) const 
  {
    return std::swap_ranges(first1, last1, first2);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
