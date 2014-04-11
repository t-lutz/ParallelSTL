#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator1, class InputIterator2>
    bool seq::includes(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2){
    return std::includes(first1, last1, first2, last2);
  }


  template<class InputIterator1, class InputIterator2, class Compare>
    bool seq::includes(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2,
                       Compare comp){
    return std::includes(first1, last1, first2, last2, comp);
  }

} // namespace policy
} // namespace parallel
} // namespace std
