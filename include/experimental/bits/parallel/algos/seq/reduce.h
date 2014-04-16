#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class InputIterator>
    typename iterator_traits<InputIterator>::value_type
      sequential_execution_policy::reduce(InputIterator first, InputIterator last) const {
    typedef typename iterator_traits<InputIterator>::value_type T;
    return std::accumulate(first, last, T{});
  }

  template<class InputIterator, class T>
    T sequential_execution_policy::reduce(InputIterator first, InputIterator last, T init) const {
    return std::accumulate(first, last, init);
  }

  template<class InputIterator, class T, class BinaryOperation>
    T sequential_execution_policy::reduce(InputIterator first, InputIterator last, T init,
                  BinaryOperation binary_op) const {
    return std::accumulate(first, last, init, binary_op);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
