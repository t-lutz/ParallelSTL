#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator>
    pair<ForwardIterator, ForwardIterator>
      sequential_execution_policy::minmax_element(ForwardIterator first, ForwardIterator last) const {
    return std::minmax_element(first, last);
  }

  template<class ForwardIterator, class Compare>
    pair<ForwardIterator, ForwardIterator>
      sequential_execution_policy::minmax_element(ForwardIterator first, ForwardIterator last, 
                                                  Compare comp) const {
    return std::minmax_element(first, last, comp);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
