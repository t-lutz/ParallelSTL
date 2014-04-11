#include "gtest/gtest.h"

#include <vector>
#include <cstdlib>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(generate_n, Lambda){
  std::vector<int> v(100);

  std::generate_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), v.size(),
                  [](){ return std::rand() % 100 + 123; });

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_TRUE(i >= 123);
    EXPECT_TRUE(i <= 222);
  }
}


TEST(generate_n, Functor){
  std::vector<int> v(100);

  struct Functor {
    int operator()() {
      return std::rand() % 100 + 123;
    }
  } f;

  std::generate_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), v.size(),
                  f);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_TRUE(i >= 123);
    EXPECT_TRUE(i <= 222);
  }
}


TEST(generate_n, Empty){
  std::vector<int> v;

  std::generate_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), 0,
                  [](){ return 1; });

  EXPECT_TRUE(v.empty());
}


TEST(generate_n, Negative){
  std::vector<int> v(100);

  std::generate_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), -100,
                  [](){ return 1; });

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_EQ(0, i);
  }
}


