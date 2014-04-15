#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator>
    ForwardIterator
      sequential_execution_policy::rotate(ForwardIterator first, ForwardIterator middle,
                  ForwardIterator last) const {
    std::rotate(first, middle, last);
    // only fine for random access operators
    // TODO: extend for generic forward iterators
    return first + (last - middle);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
