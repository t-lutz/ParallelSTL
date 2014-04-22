#include "gtest/gtest.h"

#include <vector>
#include <cstdlib>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(generate, Lambda){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v(100);

  generate(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                begin(v), end(v),
                [](){ return rand() % 100 + 123; });

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_TRUE(i >= 123);
    EXPECT_TRUE(i <= 222);
  }
}


TEST(generate, Functor){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v(100);

  struct Functor {
    int operator()() {
      return rand() % 100 + 123;
    }
  } f;

  generate(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                begin(v), end(v),
                f);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_TRUE(i >= 123);
    EXPECT_TRUE(i <= 222);
  }
}


TEST(generate, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  generate(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                begin(v), end(v),
                [](){ return rand() % 100 + 123; });

  EXPECT_TRUE(v.empty());
}

