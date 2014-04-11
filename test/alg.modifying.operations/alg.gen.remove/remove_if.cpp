#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(remove_if, Present_unique){
        std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const std::vector<int> g{1,2,3,4,5,6,  8,9,10,11,12};

  auto range = 
  std::remove_if(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 [](const int &i) { return i == 7;});

  EXPECT_EQ(std::distance(g.begin(), g.end()), std::distance(v.begin(), range)); 
  EXPECT_TRUE(std::equal(v.begin(), range, g.begin()));
}

TEST(remove_if, Present_multiple){
        std::vector<int> v{1,2,3,4,5,6,7,8,9,10,7,7};
  const std::vector<int> g{1,2,3,4,5,6,  8,9,10    };

  auto range =
  std::remove_if(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 [](const int &i) { return i == 7;});

  EXPECT_EQ(std::distance(g.begin(), g.end()), std::distance(v.begin(), range));
  EXPECT_TRUE(std::equal(v.begin(), range, g.begin()));
}

TEST(remove_if, Missing){
        std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const std::vector<int> g{1,2,3,4,5,6,7,8,9,10,11,12};

  auto range =
  std::remove_if(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 [](const int &i) { return i == 20;});

  EXPECT_EQ(std::distance(g.begin(), g.end()), std::distance(v.begin(), range));
  EXPECT_TRUE(std::equal(v.begin(), range, g.begin()));
}

TEST(remove_if, Empty){
  std::vector<int> v, g;

  auto range =
  std::remove_if(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 [](const int &i) { return true;});

  EXPECT_EQ(std::distance(g.begin(), g.end()), std::distance(v.begin(), range));
  EXPECT_TRUE(std::equal(v.begin(), range, g.begin()));
}

