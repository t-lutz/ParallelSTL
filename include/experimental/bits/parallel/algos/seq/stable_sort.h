#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class RandomAccessIterator>
    void seq::stable_sort(RandomAccessIterator first, RandomAccessIterator last){
    std::stable_sort(first, last);
  }

  template<class RandomAccessIterator, class Compare>
    void seq::stable_sort(RandomAccessIterator first, RandomAccessIterator last,
                          Compare comp){
    std::stable_sort(first, last, comp);
  }

} // namespace policy
} // namespace parallel
} // namespace std
