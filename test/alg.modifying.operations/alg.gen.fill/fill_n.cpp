#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(fill_n, Lambda){
  std::vector<int> v(100);

  std::fill_n(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              std::begin(v), v.size(),
              1);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_EQ(1, i);
  }
}


TEST(fill_n, Empty){
  std::vector<int> v;

  std::fill_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), 0,
                  1);

  EXPECT_TRUE(v.empty());
}


TEST(fill_n, Negative){
  std::vector<int> v(100);

  std::fill_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), -100,
                  1);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_EQ(0, i);
  }
}


