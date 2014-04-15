#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator, class T>
    void parallel_execution_policy::replace(ForwardIterator first, ForwardIterator last,
                      const T& old_value, const T& new_value) const {
      static const auto __replace = 
              (void(*)(ForwardIterator, ForwardIterator, const T&, const T&))
                &replace<ForwardIterator, T>;

      detail::diffract(first, last, __replace, old_value, new_value);
    }

} // namespace parallel
} // namespace experimental
} // namespace std
