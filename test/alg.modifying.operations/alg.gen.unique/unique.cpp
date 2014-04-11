#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(unique, Empty){
  using namespace std;
  vector<int> v;
  vector<int> w = v;
  
  auto it = unique(
#ifdef EXECUTION_POLICY
                   EXECUTION_POLICY,
#endif
                   begin(v), end(v));

  EXPECT_TRUE(v.empty());
  EXPECT_TRUE(distance(begin(v), it) == 0);
  EXPECT_TRUE(v == w);
}

TEST(unique, Unique){
  using namespace std;
  vector<int> v = {1,2,4,5,6,7,8,9};
  vector<int> w = v;
  
  auto it = unique(
#ifdef EXECUTION_POLICY
                   EXECUTION_POLICY,
#endif
                   begin(v), end(v));

  EXPECT_TRUE(v.size() == w.size());
  EXPECT_TRUE(it == end(v));
  EXPECT_TRUE(v == w);
}

TEST(unique, NonConseqUnique){
  using namespace std;
  vector<int> v = {1,2,4,5,6,7,8,9,8,7,6,5,4,3,2,1};
  vector<int> w = v;
  
  auto it = unique(
#ifdef EXECUTION_POLICY
                   EXECUTION_POLICY,
#endif
                   begin(v), end(v));

  EXPECT_TRUE(v.size() == w.size());
  EXPECT_TRUE(it == end(v));
  EXPECT_TRUE(v == w);
}

TEST(unique, Duplicates){
  using namespace std;
  vector<int> v = {1,2,2,2,4,4,5,6,7,7,8,9,2,4};
  vector<int> w = {1,2,    4,  5,6,7,  8,9,2,4};

  const auto diff = v.size() - w.size();
  
  auto it = unique(
#ifdef EXECUTION_POLICY
                   EXECUTION_POLICY,
#endif
                   begin(v), end(v));

  EXPECT_TRUE(distance(begin(v), it) == w.size());
  EXPECT_TRUE(equal(begin(v), it, begin(w)));
}

// TODO: The comp function should be different from default
bool myComp (int i, int j) { return i==j; }

TEST(unique, EmptyComp){
  using namespace std;
  vector<int> v;
  vector<int> w = v;
  
  auto it = unique(
#ifdef EXECUTION_POLICY
                   EXECUTION_POLICY,
#endif
                   begin(v), end(v), myComp);

  EXPECT_TRUE(v.empty());
  EXPECT_TRUE(distance(begin(v), it) == 0);
  EXPECT_TRUE(v == w);
}

TEST(unique, UniqueComp){
  using namespace std;
  vector<int> v = {1,2,4,5,6,7,8,9};
  vector<int> w = v;
  
  auto it = unique(
#ifdef EXECUTION_POLICY
                   EXECUTION_POLICY,
#endif
                   begin(v), end(v), myComp);

  EXPECT_TRUE(v.size() == w.size());
  EXPECT_TRUE(it == end(v));
  EXPECT_TRUE(v == w);
}

TEST(unique, NonConseqUniqueComp){
  using namespace std;
  vector<int> v = {1,2,4,5,6,7,8,9,8,7,6,5,4,3,2,1};
  vector<int> w = v;
  
  auto it = unique(
#ifdef EXECUTION_POLICY
                   EXECUTION_POLICY,
#endif
                   begin(v), end(v), myComp);

  EXPECT_TRUE(v.size() == w.size());
  EXPECT_TRUE(it == end(v));
  EXPECT_TRUE(v == w);
}

TEST(unique, DuplicatesComp){
  using namespace std;
  vector<int> v = {1,2,2,2,4,4,5,6,7,7,8,9,2,4};
  vector<int> w = {1,2,    4,  5,6,7,  8,9,2,4};

  const auto diff = v.size() - w.size();
  
  auto it = unique(
#ifdef EXECUTION_POLICY
                   EXECUTION_POLICY,
#endif
                   begin(v), end(v), myComp);

  EXPECT_TRUE(distance(begin(v), it) == w.size());
  EXPECT_TRUE(equal(begin(v), it, begin(w)));
}


