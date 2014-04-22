#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(fill_n, Lambda){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v(100);

  fill_n(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), v.size(),
              1);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_EQ(1, i);
  }
}


TEST(fill_n, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  fill_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  begin(v), 0,
                  1);

  EXPECT_TRUE(v.empty());
}


TEST(fill_n, Negative){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v(100);

  fill_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  begin(v), -100,
                  1);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_EQ(0, i);
  }
}


