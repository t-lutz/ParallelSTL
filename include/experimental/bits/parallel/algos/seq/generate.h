#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace experimental {
namespace parallel {

  template<class ForwardIterator, class Generator>
    void sequential_execution_policy::generate(ForwardIterator first, ForwardIterator last, Generator gen){
    std::generate(first, last, gen);
  }

} // namespace parallel
} // namespace experimental
} // namespace std
