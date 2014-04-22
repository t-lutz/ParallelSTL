#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(fill, Simple){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v(100);

  fill(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v),
            123);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_EQ(123, 123);
  }
}


TEST(fill, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v;

  fill(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                begin(v), end(v),
                1);

  EXPECT_TRUE(v.empty());
}

