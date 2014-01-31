#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(none_of, True) {
  std::vector<int> v{1,2,3,4,5,6,7,8,9};

  // everything is less than 10
  EXPECT_TRUE(std::none_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          std::begin(v), std::end(v),
                          [](const int &i){ return i == 10; }));
}

TEST(none_of, False) {
  std::vector<int> v{1,2,3,4,5,6,7,8,9};

  // not everything is 1
  EXPECT_FALSE(std::none_of(
#ifdef EXECUTION_POLICY
                           EXECUTION_POLICY,
#endif
                           std::begin(v), std::end(v),
                           [](const int &i){ return i == 1; }));
}

TEST(none_of, Empty) {
  std::vector<int> v;
  
  // empty range should return true regardless of the predicate
  EXPECT_TRUE(std::none_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          std::begin(v), std::end(v),
                          [](const int &i){ return false; }));
}

