#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator>
    bool sequential_execution_policy::is_heap(ForwardIterator first, ForwardIterator last){
    return std::is_heap(first, last);
  }


  template<class ForwardIterator, class Compare>
    bool sequential_execution_policy::is_heap(ForwardIterator first, ForwardIterator last,
                        Compare comp){
    return std::is_heap(first, last, comp);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
