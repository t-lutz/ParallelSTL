#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class OutputIterator, class Size, class T>
    void sequential_execution_policy::fill_n(OutputIterator first, Size n, const T& value){
    std::fill_n(first, n, value);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
