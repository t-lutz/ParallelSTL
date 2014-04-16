#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(is_sorted, Empty){
  using namespace std;
  const vector<int> v;
  
  EXPECT_TRUE(is_sorted(
#ifdef EXECUTION_POLICY
                        EXECUTION_POLICY,
#endif
                        begin(v), end(v)));
}

TEST(is_sorted, Sorted) {
  using namespace std;
  const vector<int> v = { 1,2,3,4,5,7,8,9};
  
  EXPECT_TRUE(is_sorted(
#ifdef EXECUTION_POLICY
                        EXECUTION_POLICY,
#endif
                        begin(v), end(v)));
}

TEST(is_sorted, SortedDuplicates){
  using namespace std;
  const vector<int> v = { 1,2,3,4,4,4,5,5,7,8,8,9};
  
  EXPECT_TRUE(is_sorted(
#ifdef EXECUTION_POLICY
                        EXECUTION_POLICY,
#endif
                        begin(v), end(v)));
}

TEST(is_sorted, Unsorted){
  using namespace std;
  const vector<int> v = { 8,4,6,7,1,5,9,4,57,2,1};
  
  EXPECT_FALSE(is_sorted(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         begin(v), end(v)));
}

bool mySortingComp (int i,int j) { return i>j; }

TEST(is_sorted, EmptyComp){
  using namespace std;
  const vector<int> v;
  
  EXPECT_TRUE(is_sorted(
#ifdef EXECUTION_POLICY
                        EXECUTION_POLICY,
#endif
                        begin(v), end(v), mySortingComp));
}

TEST(is_sorted, SortedComp) {
  using namespace std;
  const vector<int> v = {9,8,7,6,5,4,3,2,1};
  
  EXPECT_TRUE(is_sorted(
#ifdef EXECUTION_POLICY
                        EXECUTION_POLICY,
#endif
                        begin(v), end(v), mySortingComp));
}

TEST(is_sorted, SortedDuplicatesComp){
  using namespace std;
  const vector<int> v = {9,8,8,7,6,6,6,5,4,4,3,2,2,2,1};
  
  EXPECT_TRUE(is_sorted(
#ifdef EXECUTION_POLICY
                        EXECUTION_POLICY,
#endif
                        begin(v), end(v), mySortingComp));
}

TEST(is_sorted, UnsortedComp){
  using namespace std;
  const vector<int> v = { 8,4,6,7,1,5,9,4,57,2,1};
  
  EXPECT_FALSE(is_sorted(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         begin(v), end(v), mySortingComp));
}


