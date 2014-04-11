#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class OutputIterator, class Size, class Generator>
    OutputIterator seq::generate_n(OutputIterator first, Size n, Generator gen){
    return std::generate_n(first, n, gen);
  }

} // namespace policy
} // namespace parallel
} // namespace std
