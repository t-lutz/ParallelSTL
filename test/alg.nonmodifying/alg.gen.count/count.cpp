#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

#ifndef EXECUTION_POLICY
#include <parallel/algorithm>
#endif

TEST(count, None){
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     std::count(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              std::begin(v), std::end(v),
              20);

  EXPECT_EQ(0, value); 
}

TEST(count, One){
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     std::count(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              std::begin(v), std::end(v),
              1);

  EXPECT_EQ(1, value); 
}

TEST(count, Many){
  std::vector<int> v{1,2,3,4,5,1,7,8,9,10,1,1};

  auto value = 
     std::count(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              std::begin(v), std::end(v),
              1);

  EXPECT_EQ(4, value); 
}

TEST(count, Empty){
  std::vector<int> v;

  auto value = 
     std::count(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              std::begin(v), std::end(v),
              1);

  EXPECT_EQ(0, value); 
}

