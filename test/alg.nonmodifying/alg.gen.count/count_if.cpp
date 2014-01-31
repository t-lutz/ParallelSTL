#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(count_if, None){
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     std::count_if(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              std::begin(v), std::end(v),
              [](const int &i){return i > 20;});

  EXPECT_EQ(0, value); 
}

TEST(count_if, One){
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     std::count_if(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              std::begin(v), std::end(v),
              [](const int &i){return i == 2;});

  EXPECT_EQ(1, value); 
}

TEST(count_if, Many){
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     std::count_if(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              std::begin(v), std::end(v),
              [](const int &i){return i < 8;});

  EXPECT_EQ(7, value); 
}

TEST(count_if, Empty){
  std::vector<int> v;

  auto value = 
     std::count_if(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              std::begin(v), std::end(v),
              [](const int &i){return true;});

  EXPECT_EQ(0, value); 
}

