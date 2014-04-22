#include "gtest/gtest.h"

#include <vector>
#include <cstdlib>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(generate_n, Lambda){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v(100);

  generate_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  begin(v), v.size(),
                  [](){ return rand() % 100 + 123; });

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_TRUE(i >= 123);
    EXPECT_TRUE(i <= 222);
  }
}


TEST(generate_n, Functor){
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

  generate_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  begin(v), v.size(),
                  f);

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_TRUE(i >= 123);
    EXPECT_TRUE(i <= 222);
  }
}


TEST(generate_n, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  generate_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  begin(v), 0,
                  [](){ return 1; });

  EXPECT_TRUE(v.empty());
}


TEST(generate_n, Negative){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v(100);

  generate_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  begin(v), -100,
                  [](){ return 1; });

  EXPECT_EQ(100, v.size());
  for(auto i : v){
    EXPECT_EQ(0, i);
  }
}


