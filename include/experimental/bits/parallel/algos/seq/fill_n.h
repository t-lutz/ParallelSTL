#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class OutputIterator, class Size, class T>
    void seq::fill_n(OutputIterator first, Size n, const T& value){
    std::fill_n(first, n, value);
  }

} // namespace policy
} // namespace parallel
} // namespace std
