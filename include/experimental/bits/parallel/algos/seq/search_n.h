#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class ForwardIterator, class Size, class T>
    ForwardIterator seq::search_n(ForwardIterator first, ForwardIterator last, Size count,
                                  const T& value){
    return std::search_n(first, last, count, value);
  }

  template<class ForwardIterator, class Size, class T, class BinaryPredicate>
    ForwardIterator seq::search_n(ForwardIterator first, ForwardIterator last, Size count,
                                  const T& value, BinaryPredicate pred){
    return std::search_n(first, last, count, value, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
