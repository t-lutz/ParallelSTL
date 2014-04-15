#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator, class Size, class T>
    ForwardIterator sequential_execution_policy::search_n(ForwardIterator first, ForwardIterator last, Size count,
                                  const T& value) const {
    return std::search_n(first, last, count, value);
  }

  template<class ForwardIterator, class Size, class T, class BinaryPredicate>
    ForwardIterator sequential_execution_policy::search_n(ForwardIterator first, ForwardIterator last, Size count,
                                  const T& value, BinaryPredicate pred) const {
    return std::search_n(first, last, count, value, pred);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
