#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

 template<class InputIterator, class OutputIterator>
    OutputIterator sequential_execution_policy::copy(InputIterator first, InputIterator last,
                             OutputIterator result){
    return std::copy(first, last, result);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
