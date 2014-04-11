#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

 template<class InputIterator, class OutputIterator>
    OutputIterator seq::copy(InputIterator first, InputIterator last,
                             OutputIterator result){
    return std::copy(first, last, result);
  }

} // namespace policy
} // namespace parallel
} // namespace std
