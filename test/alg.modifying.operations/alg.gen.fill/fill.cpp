#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(fill, Simple){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v(10000);

  fill(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v),
            123);

  EXPECT_EQ(10000, v.size());
  for(auto i : v){
    EXPECT_EQ(123, v[i]);
  }
}

TEST(fill, partial){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v(10000);
  v[800]=23;
  v[900]=42;

  fill(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), next(begin(v),800),
            123);

  EXPECT_EQ(10000, v.size());
  for(auto i=0; i < 800; i++){
    EXPECT_EQ(123, v[i]);
  }
  EXPECT_EQ(42, v[900]);
  EXPECT_EQ(23, v[800]);
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

