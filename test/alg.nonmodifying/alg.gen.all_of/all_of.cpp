#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

#ifndef EXECUTION_POLICY
#define EXECUTION_POLICY std::seq
#endif

TEST(all_of, Basic) {
  std::vector<int> v{1,2,3,4,5,6,7,8,9};

  // everything is less than 10
  EXPECT_TRUE(std::all_of(//EXECUTION_POLICY,
                          std::begin(v), std::end(v),
                          [](const int &i){ return i < 10; }));

  // not everything is 1
  EXPECT_FALSE(std::all_of(//EXECUTION_POLICY,
                           std::begin(v), std::end(v),
                           [](const int &i){ return i == 1; }));
}

TEST(all_of, Empty) {
  std::vector<int> v;
  
  // empty range should return true regardless of the predicate
  EXPECT_TRUE(std::all_of(//EXECUTION_POLICY,
                          std::begin(v), std::end(v),
                          [](const int &i){ return false; }));
}

