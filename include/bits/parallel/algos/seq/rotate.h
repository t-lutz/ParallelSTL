#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator>
    ForwardIterator
      seq::rotate(ForwardIterator first, ForwardIterator middle,
                  ForwardIterator last){
    std::rotate(first, middle, last);
    // only fine for random access operators
    // TODO: extend for generic forward iterators
    return first + (last - middle);
  }

} // namespace policy
} // namespace parallel
} // namespace std
