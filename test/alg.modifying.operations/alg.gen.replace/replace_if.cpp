#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(replace_if, Present_unique){
        std::vector<int> v{1,2,3,4,5,6, 7,8,9,10,11,12};
  const std::vector<int> g{1,2,3,4,5,6,77,8,9,10,11,12};

  std::replace_if(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), std::end(v),
                  [](const int &i) { return i == 7;} , 77);

  EXPECT_EQ(g, v); 
}

TEST(replace_if, Present_multiple){
        std::vector<int> v{1,2,3,4,5,6, 7,8,9,10, 7, 7};
  const std::vector<int> g{1,2,3,4,5,6,77,8,9,10,77,77};

  std::replace_if(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), std::end(v),
                  [](const int &i) { return i == 7;}, 77);

  EXPECT_EQ(g, v); 
}

TEST(replace_if, Missing){
        std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const std::vector<int> g{1,2,3,4,5,6,7,8,9,10,11,12};

  std::replace_if(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 [](const int &i) { return i == 20;}, 0);

  EXPECT_EQ(g, v); 
}

TEST(replace_if, Empty){
  std::vector<int> v, g;

  std::replace_if(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 [](const int &i) { return true;}, 1);

  EXPECT_EQ(g, v); 
}

