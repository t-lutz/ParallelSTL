#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator>
    ForwardIterator seq::min_element(ForwardIterator first, ForwardIterator last){
    return std::min_element(first, last);
  }


  template<class ForwardIterator, class Compare>
    ForwardIterator seq::min_element(ForwardIterator first, ForwardIterator last,
                                Compare comp){
    return std::min_element(first, last, comp);
  }

} // namespace policy
} // namespace parallel
} // namespace std
