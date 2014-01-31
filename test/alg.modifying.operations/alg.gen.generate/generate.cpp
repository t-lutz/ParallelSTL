#include "gtest/gtest.h"

#include <vector>
#include <cstdlib>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(generate, Lambda){
  std::vector<int> v(100);

  std::generate(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                std::begin(v), std::end(v),
                [](){ return std::rand() % 100 + 123; });

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_TRUE(i >= 123);
    EXPECT_TRUE(i <= 222);
  }
}


TEST(generate, Functor){
  std::vector<int> v(100);

  struct Functor {
    int operator()() {
      return std::rand() % 100 + 123;
    }
  } f;

  std::generate(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                std::begin(v), std::end(v),
                f);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_TRUE(i >= 123);
    EXPECT_TRUE(i <= 222);
  }
}


TEST(generate, Empty){
  std::vector<int> v;

  std::generate(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                std::begin(v), std::end(v),
                [](){ return std::rand() % 100 + 123; });

  EXPECT_TRUE(v.empty());
}

