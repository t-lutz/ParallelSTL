#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator1, class InputIterator2>
    bool sequential_execution_policy::includes(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2) const {
    return std::includes(first1, last1, first2, last2);
  }


  template<class InputIterator1, class InputIterator2, class Compare>
    bool sequential_execution_policy::includes(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       Compare comp) const {
    return std::includes(first1, last1, first2, last2, comp);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
