#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator>
    ForwardIterator seq::is_sorted_until(ForwardIterator first, ForwardIterator last){
    return std::is_sorted_until(first, last);
  }

  template<class ForwardIterator, class Compare>
    ForwardIterator seq::is_sorted_until(ForwardIterator first, ForwardIterator last,
                                         Compare comp){
    return std::is_sorted_until(first, last, comp);
  }


} // namespace policy
} // namespace parallel
} // namespace std
