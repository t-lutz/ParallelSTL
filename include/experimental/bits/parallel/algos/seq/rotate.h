#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  template<class ForwardIterator>
    ForwardIterator
      sequential_execution_policy::rotate(ForwardIterator first, ForwardIterator middle,
                  ForwardIterator last) const {
    std::rotate(first, middle, last);
    // TODO: this is not optimal.
    advance(first, distance(middle, last));
    return first;
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
