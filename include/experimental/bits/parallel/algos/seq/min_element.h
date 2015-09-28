#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator>
    ForwardIterator sequential_execution_policy::min_element(ForwardIterator first, 
                                                             ForwardIterator last) const {
    return std::min_element(first, last);
  }


  template<class ForwardIterator, class Compare>
    ForwardIterator sequential_execution_policy::min_element(ForwardIterator first, 
                                                             ForwardIterator last,
                                                             Compare comp) const {
    return std::min_element(first, last, comp);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
