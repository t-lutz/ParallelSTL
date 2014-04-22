#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(is_partitioned, Patitioned){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{1,3,5,7,9,11,2,4,6,8,10,12};

  EXPECT_TRUE(is_partitioned(
#ifdef EXECUTION_POLICY
                             EXECUTION_POLICY,
#endif
                             begin(v), end(v),
                             [](const int &i){ return i % 2 == 1;}));
}

TEST(is_partitioned, NotPatitioned){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  EXPECT_FALSE(is_partitioned(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v),
                              [](const int &i){ return i % 2 == 1;}));
}

TEST(is_partitioned, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v;

  EXPECT_TRUE(is_partitioned(
#ifdef EXECUTION_POLICY
                             EXECUTION_POLICY,
#endif
                             begin(v), end(v),
                             [](const int &i){ return i % 2 == 1;}));
}



