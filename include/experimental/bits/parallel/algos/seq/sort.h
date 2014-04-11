#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class RandomAccessIterator>
    void seq::sort(RandomAccessIterator first, RandomAccessIterator last){
    std::sort(first, last);
  }

  template<class RandomAccessIterator, class Compare>
    void seq::sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp){
    std::sort(first, last, comp);
  }

} // namespace policy
} // namespace parallel
} // namespace std
