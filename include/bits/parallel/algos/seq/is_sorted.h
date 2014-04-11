#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator>
    bool seq::is_sorted(ForwardIterator first, ForwardIterator last){
    return std::is_sorted(first, last);
  }


  template<class ForwardIterator, class Compare>
    bool seq::is_sorted(ForwardIterator first, ForwardIterator last,
                        Compare comp){
    return std::is_sorted(first, last, comp);
  }

} // namespace policy
} // namespace parallel
} // namespace std
