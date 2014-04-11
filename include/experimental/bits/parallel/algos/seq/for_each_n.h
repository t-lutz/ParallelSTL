#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class Size, class Function>
    Function seq::for_each_n(InputIterator first, Size n,
                        Function f){
    return std::for_each(first, first + n, f);
  }

} // namespace policy
} // namespace parallel
} // namespace std
