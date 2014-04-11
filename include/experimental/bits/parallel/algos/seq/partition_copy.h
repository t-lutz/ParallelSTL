#ifndef _EXPERIMENTAL_N3554_POLICY_SEQUENTIAL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>

namespace std {
namespace parallel {
namespace policy {

  template<class InputIterator, class OutputIterator1,
           class OutputIterator2, class Predicate>
  pair<OutputIterator1, OutputIterator2>
  seq::partition_copy(InputIterator first, InputIterator last,
                      OutputIterator1 out_true, OutputIterator2 out_false,
                      Predicate pred){
    return partition_copy(first, last, out_true, out_false, pred);
  }

} // namespace policy
} // namespace parallel
} // namespace std
