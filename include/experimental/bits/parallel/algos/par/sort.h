#ifndef _EXPERIMENTAL_N3554_POLICY_PARALLEL
#error Include <parallel/algorithm> or <parallel/utility>
#endif

#include <algorithm>
#include <experimental/bits/parallel/algos/par/diffract.h> 
#include <vector>

namespace std {
namespace experimental {
namespace parallel {

  template<class RandomAccessIterator>
    void parallel_execution_policy::sort(RandomAccessIterator first, RandomAccessIterator last) const 
  {
    return this->sort(first, last, std::less<typename iterator_traits<RandomAccessIterator>::value_type>());
  }

  template<class RandomAccessIterator, class Compare>
    void parallel_execution_policy::sort(RandomAccessIterator first, RandomAccessIterator last, 
                                           Compare comp) const 
  {
    // 2 stage sort:
    // - stage 1: divide the range and sort sub-ranges individually
    // - stage 2: tree reduction using std::inplace_merge

    // stage 1
    detail::diffract(first, last, std::sort<RandomAccessIterator, Compare>, comp);

    // stage 2
    // TODO: we could use the parallel version of std::inplace_merge
    
    // split the ranges
    auto ranges = detail::splitRange(first, last);

    // begin/middle/end triple for inplace_merge
    struct Triple {RandomAccessIterator begin, middle, end;};

    // tree reduction for inplace_merge, until there is only one range
    while(ranges.size() > 1){
      // container for the sub-ranges at the next reduction level
      vector<pair<RandomAccessIterator,RandomAccessIterator>> new_ranges;

      // group the sub-ranges in triples instead of pairs
      vector<Triple> merge_ranges;
      for(auto it = begin(ranges); it != end(ranges); ++it){
        auto n = next(it);
        // if there is a next pair, create a triple
        if(n != end(ranges)){
          new_ranges.push_back(make_pair(it->first, n->second));
          merge_ranges.push_back({it->first, it->second, n->second});
          it++;
        }
        // otherwise it is an orphan range, add it to the list of sub-ranges
        else {
          new_ranges.push_back(*it);
        }
      }

      // merge the triples in pairs
      auto merge_op = 
        [&](const Triple & t) {
          std::inplace_merge(t.begin, t.middle, t.end, comp);
        };
      detail::diffract(begin(merge_ranges), end(merge_ranges), 
                       std::for_each<typename vector<Triple>::iterator, decltype(merge_op)>,
                       merge_op);

      // move to the next reduction level.
      ranges = new_ranges;
    }
  }

} // namespace parallel
} // namespace experimental
} // namespace std
