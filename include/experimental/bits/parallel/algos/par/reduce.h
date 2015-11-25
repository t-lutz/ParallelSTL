#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h>

namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

  namespace detail {
    template<class InputIterator, class T, class BinaryOperation>
    T partial_reduce(InputIterator first, InputIterator last, BinaryOperation op)
    {
      typename std::iterator_traits<InputIterator>::value_type sum = *first;
      while (++first != last) sum = op(sum, *first);
      return sum;
    }
  } 

  template<class InputIterator, class T, class BinaryOperation>
    T parallel_execution_policy::reduce(InputIterator first, InputIterator last, T init,
                  BinaryOperation binary_op) const 
  {
    if(first == last) return init;
    return binary_op(detail::diffract_gather(first, last, 
                                             detail::partial_reduce,
                                             binary_op), init);
  }

  template<class InputIterator, class T>
    T parallel_execution_policy::reduce(InputIterator first, InputIterator last, T init) const 
  {
    return this->reduce(first, last, init, ::std::plus<T>());
  }

  template<class InputIterator>
    typename iterator_traits<InputIterator>::value_type
      parallel_execution_policy::reduce(InputIterator first, InputIterator last) const {
    typedef typename iterator_traits<InputIterator>::value_type T;
    return this->reduce(first, last, T{});
  }

} // namespace v1
} // namespace parallel
} // namespace experimental
} // namespace std
