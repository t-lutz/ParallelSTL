#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator>
    ForwardIterator sequential_execution_policy::is_heap_until(ForwardIterator first, ForwardIterator last) const {
    return std::is_heap_until(first, last);
  }

  template<class ForwardIterator, class Compare>
    ForwardIterator sequential_execution_policy::is_heap_until(ForwardIterator first, ForwardIterator last,
                                                               Compare comp) const {
    return std::is_heap_until(first, last, comp);
  }


} // namespace parallel
} // namespace experimental
} // namespace std
