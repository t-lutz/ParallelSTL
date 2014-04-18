#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator>
    bool parallel_execution_policy::is_sorted(ForwardIterator first, ForwardIterator last) const 
  {
    return this->is_sorted_until(first, last) == last;
  }


  template<class ForwardIterator, class Compare>
    bool parallel_execution_policy::is_sorted(ForwardIterator first, ForwardIterator last,
                        Compare comp) const 
  {
    return this->is_sorted_until(first, last, comp) == last;
  }

} // namespace parallel
} // namespace experimental
} // namespace std
