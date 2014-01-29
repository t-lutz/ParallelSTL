#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

#ifndef EXECUTION_POLICY
#include <parallel/algorithm>
#endif

TEST(any_of, True) {
  std::vector<int> v{1,2,3,4,5,6,7,8,9};

  // everything is less than 10
  EXPECT_TRUE(std::any_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          std::begin(v), std::end(v),
                          [](const int &i){ return i == 2; }));
}

TEST(any_of, False) {
  std::vector<int> v{1,2,3,4,5,6,7,8,9};

  // not everything is 1
  EXPECT_FALSE(std::any_of(
#ifdef EXECUTION_POLICY
                           EXECUTION_POLICY,
#endif
                           std::begin(v), std::end(v),
                           [](const int &i){ return i == 10; }));
}

TEST(any_of, Empty) {
  std::vector<int> v;
  
  // empty range should return false regardless of the predicate
  EXPECT_FALSE(std::any_of(
#ifdef EXECUTION_POLICY
                            EXECUTION_POLICY,
#endif
                            std::begin(v), std::end(v),
                            [](const int &i){ return true; }));
}

