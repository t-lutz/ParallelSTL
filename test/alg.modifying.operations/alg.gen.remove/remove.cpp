#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(remove, Present_unique){
        std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const std::vector<int> g{1,2,3,4,5,6,  8,9,10,11,12};

  auto range = 
    std::remove(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 7);

  EXPECT_EQ(std::distance(g.begin(), g.end()), std::distance(v.begin(), range)); 
  EXPECT_TRUE(std::equal(v.begin(), range, g.begin()));
}

TEST(remove, Present_multiple){
        std::vector<int> v{1,2,3,4,5,6,7,8,9,10,7,7};
  const std::vector<int> g{1,2,3,4,5,6,  8,9,10    };

  auto range =
     std::remove(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 7);

  EXPECT_EQ(std::distance(g.begin(), g.end()), std::distance(v.begin(), range));
  EXPECT_TRUE(std::equal(v.begin(), range, g.begin()));
}

TEST(remove, Missing){
        std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const std::vector<int> g{1,2,3,4,5,6,7,8,9,10,11,12};

  auto range =
     std::remove(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 20);

  EXPECT_EQ(std::distance(g.begin(), g.end()), std::distance(v.begin(), range));
  EXPECT_TRUE(std::equal(v.begin(), range, g.begin()));
}

TEST(remove, Empty){
  std::vector<int> v, g;

  auto range =
     std::remove(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 0);

  EXPECT_EQ(std::distance(g.begin(), g.end()), std::distance(v.begin(), range));
  EXPECT_TRUE(std::equal(v.begin(), range, g.begin()));
}

