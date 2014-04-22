// TODO: integrate C++14 prototypes when an implementation of C++14 is available.

#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(equal, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v, w;
  
  EXPECT_TRUE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), end(v), begin(w)));
}


TEST(equal, Equal){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v = {1,2,3,4,5,6,7,8,9};
  vector<int> w = {1,2,3,4,5,6,7,8,9};

  EXPECT_TRUE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), end(v), begin(w)));
}

TEST(equal, EqualSubset){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v = {1,2,3,4,5,6,7,8,9};
  vector<int> w = {1,2,3,4,5,6,7,8,9,10,11,12,13};

  EXPECT_TRUE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), end(v), begin(w)));
}

TEST(equal, NotEqual){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v = {1,2,3,4,5,6,7,8,9};
  vector<int> w = {8,4,2,1,7,3,6,8,4};

  EXPECT_FALSE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), end(v), begin(w)));
}

TEST(equal, EmptyRange){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v = {8,4,7,4,5,1,23,4,7};
  vector<int> w = {1,2,3,4,5,6,7,8,9};

  EXPECT_TRUE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), begin(v), begin(w)));
}


// TODO: the predicate should be more interesting
bool myPred(int a, int b) { return a == b; }

TEST(equal, EmptyPred){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v, w;
  
  EXPECT_TRUE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), end(v), begin(w), myPred));
}

TEST(equal, EqualPred){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v = {1,2,3,4,5,6,7,8,9};
  vector<int> w = {1,2,3,4,5,6,7,8,9};

  EXPECT_TRUE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), end(v), begin(w), myPred));
}

TEST(equal, EqualSubsetPred){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v = {1,2,3,4,5,6,7,8,9};
  vector<int> w = {1,2,3,4,5,6,7,8,9,10,11,12,13};

  EXPECT_TRUE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), end(v), begin(w), myPred));
}

TEST(equal, NotEqualPred){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v = {1,2,3,4,5,6,7,8,9};
  vector<int> w = {8,4,2,1,7,3,6,8,4};

  EXPECT_FALSE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), end(v), begin(w), myPred));
}

TEST(equal, EmptyRangePred){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v = {8,4,7,4,5,1,23,4,7};
  vector<int> w = {1,2,3,4,5,6,7,8,9};

  EXPECT_TRUE(equal(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    begin(v), begin(v), begin(w), myPred));
}


// TODO: C++14 functions...



