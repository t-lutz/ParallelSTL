#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator, class Predicate, class T>
    void parallel_execution_policy::replace_if(ForwardIterator first, ForwardIterator last,
                                               Predicate pred, const T& new_value) const {
    static const auto __replace_if = 
            (void(*)(ForwardIterator, ForwardIterator, Predicate, const T&))
              &replace_if<ForwardIterator, Predicate, T>;

    detail::diffract(first, last, __replace_if, pred, new_value);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
