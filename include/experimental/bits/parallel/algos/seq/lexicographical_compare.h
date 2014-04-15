#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator1, class InputIterator2>
    bool
      sequential_execution_policy::lexicographical_compare(InputIterator1 first1, 
                                                           InputIterator1 last1,
                                                           InputIterator2 first2, 
                                                           InputIterator2 last2) const {
    return std::lexicographical_compare(first1, last1, first2, last2);
  }



  template<class InputIterator1, class InputIterator2, class Compare>
    bool
      sequential_execution_policy::lexicographical_compare(InputIterator1 first1, 
                                                           InputIterator1 last1,
                                                           InputIterator2 first2, 
                                                           InputIterator2 last2,
                                                           Compare comp) const {
    return std::lexicographical_compare(first1, last1, first2, last2, comp);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
