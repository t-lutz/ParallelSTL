#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator>
    bool sequential_execution_policy::is_heap(ForwardIterator first, ForwardIterator last) const {
    return std::is_heap(first, last);
  }


  template<class ForwardIterator, class Compare>
    bool sequential_execution_policy::is_heap(ForwardIterator first, ForwardIterator last,
                        Compare comp) const {
    return std::is_heap(first, last, comp);
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
