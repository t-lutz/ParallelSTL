#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator>
    typename iterator_traits<InputIterator>::value_type
      parallel_execution_policy::reduce(InputIterator first, InputIterator last) const {
    typedef typename iterator_traits<InputIterator>::value_type T;
    return detail::diffract_gather(first, last, 
                                   std::accumulate<InputIterator, T>,
                                   std::plus<T>(),
                                   T{0});
  }

  template<class InputIterator, class T>
    T parallel_execution_policy::reduce(InputIterator first, InputIterator last, T init) const {
    return detail::diffract_gather(first, last, 
                                   std::accumulate<InputIterator, T>,
                                   std::plus<T>(),
                                   init);
  }

  template<class InputIterator, class T, class BinaryOperation>
    T parallel_execution_policy::reduce(InputIterator first, InputIterator last, T init,
                  BinaryOperation binary_op) const {
    return detail::diffract_gather(first, last, 
                                   std::accumulate<InputIterator, T>,
                                   binary_op,
                                   init);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
