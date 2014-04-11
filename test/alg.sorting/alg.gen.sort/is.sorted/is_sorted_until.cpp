#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(is_sorted_until, Empty){
  using namespace std;
  const vector<int> v;
  
  EXPECT_TRUE(is_sorted_until(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v)) == end(v));
}

TEST(is_sorted_until, EmptyRange) {
  using namespace std;
  const vector<int> v = {3,2,1,0};
  
  EXPECT_TRUE(is_sorted_until(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), begin(v)+1) == begin(v)+1);
}


TEST(is_sorted_until, Sorted) {
  using namespace std;
  const vector<int> v = { 1,2,3,4,5,7,8,9};
  
  EXPECT_TRUE(is_sorted_until(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v)) == end(v));
}

TEST(is_sorted_until, SortedDuplicates){
  using namespace std;
  const vector<int> v = { 1,2,3,4,4,4,5,5,7,8,8,9};
  
  EXPECT_TRUE(is_sorted_until(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v)) == end(v));
}

TEST(is_sorted_until, Unsorted){
  using namespace std;
  const vector<int> v = { 1,4,6,7,1,5,9,4,57,2,1};
  
  auto it = is_sorted_until(
#ifdef EXECUTION_POLICY
                            EXECUTION_POLICY,
#endif
                            begin(v), end(v));

  EXPECT_TRUE(it - begin(v) == 4);
}


bool myComp (int i,int j) { return (i>j); }

TEST(is_sorted_until, EmptyComp){
  using namespace std;
  const vector<int> v;
  
  EXPECT_TRUE(is_sorted_until(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v), myComp) == end(v));
}

TEST(is_sorted_until, EmptyRangeComp) {
  using namespace std;
  const vector<int> v = {3,2,1,0};
  
  EXPECT_TRUE(is_sorted_until(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), begin(v)+1, myComp) == begin(v)+1);
}


TEST(is_sorted_until, SortedComp) {
  using namespace std;
  const vector<int> v = { 9,8,7,6,5,4,3,2,1};
  
  EXPECT_TRUE(is_sorted_until(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v), myComp) == end(v));
}

TEST(is_sorted_until, SortedDuplicatesComp){
  using namespace std;
  const vector<int> v = { 9,8,8,7,6,6,5,4,4,4,3,2,1,1,1};
  
  EXPECT_TRUE(is_sorted_until(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v), myComp) == end(v));
}

TEST(is_sorted_until, UnsortedComp){
  using namespace std;
  const vector<int> v = { 6,5,4,4,1,5,9,4,57,2,1};
  
  auto it = is_sorted_until(
#ifdef EXECUTION_POLICY
                            EXECUTION_POLICY,
#endif
                            begin(v), end(v), myComp);

  EXPECT_TRUE(it - begin(v) == 5);
}



