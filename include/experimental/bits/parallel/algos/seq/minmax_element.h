#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator>
    pair<ForwardIterator, ForwardIterator>
      seq::minmax_element(ForwardIterator first, ForwardIterator last){
    return std::minmax_element(first, last);
  }

  template<class ForwardIterator, class Compare>
    pair<ForwardIterator, ForwardIterator>
      seq::minmax_element(ForwardIterator first, ForwardIterator last, Compare comp){
    return std::minmax_element(first, last, comp);
  }

} // namespace policy
} // namespace parallel
} // namespace std
