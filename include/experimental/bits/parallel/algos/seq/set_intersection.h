#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class InputIterator1, class InputIterator2,
           class OutputIterator>
    OutputIterator
      sequential_execution_policy::set_intersection(InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, InputIterator2 last2,
                            OutputIterator result) const {
    return std::set_intersection(first1, last1, first2, last2, result);
  }


  template<class InputIterator1, class InputIterator2,
           class OutputIterator, class Compare>
    OutputIterator
      sequential_execution_policy::set_intersection(InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, InputIterator2 last2,
                            OutputIterator result, Compare comp) const {
    return std::set_intersection(first1, last1, first2, last2, result, comp);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
