#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(fill, Simple){
  std::vector<int> v(100);

  std::fill(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v),
            123);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_EQ(123, 123);
  }
}


TEST(fill, Empty){
  std::vector<int> v;

  std::fill(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                std::begin(v), std::end(v),
                1);

  EXPECT_TRUE(v.empty());
}

