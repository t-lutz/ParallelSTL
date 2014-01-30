#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

#ifndef EXECUTION_POLICY
#include <parallel/algorithm>
#endif

TEST(find, Present_unique){
  const std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto elt = std::find(
#ifdef EXECUTION_POLICY
                       EXECUTION_POLICY,
#endif
                       std::begin(v), std::end(v),
                       7);

  EXPECT_EQ(6, std::distance(v.begin(), elt)); 
}

TEST(find, Present_multiple){
  const std::vector<int> v{1,2,3,4,5,6,7,8,9,10,7,7};

  auto elt = std::find(
#ifdef EXECUTION_POLICY
                       EXECUTION_POLICY,
#endif
                       std::begin(v), std::end(v),
                       7);

  EXPECT_EQ(6, std::distance(v.begin(), elt)); 
}

TEST(find, Missing){
  const std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto elt = std::find(
#ifdef EXECUTION_POLICY
                       EXECUTION_POLICY,
#endif
                       std::begin(v), std::end(v),
                       20);

  EXPECT_EQ(v.end(), elt); 
}

TEST(find, Empty){
  const std::vector<int> v;

  auto elt = std::find(
#ifdef EXECUTION_POLICY
                       EXECUTION_POLICY,
#endif
                       std::begin(v), std::end(v),
                       0);

  EXPECT_EQ(v.end(), elt); 
}

