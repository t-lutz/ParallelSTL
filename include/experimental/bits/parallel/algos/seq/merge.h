#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      seq::merge(InputIterator1 first1, InputIterator1 last1,
                 InputIterator2 first2, InputIterator2 last2,
                 OutputIterator result){
    return std::merge(first1, last1, first2, last2, result);
  }


  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      seq::merge(InputIterator1 first1, InputIterator1 last1,
                 InputIterator2 first2, InputIterator2 last2,
                 OutputIterator result, Compare comp){
    return std::merge(first1, last1, first2, last2, result, comp);
  }

} // namespace policy
} // namespace parallel
} // namespace std
