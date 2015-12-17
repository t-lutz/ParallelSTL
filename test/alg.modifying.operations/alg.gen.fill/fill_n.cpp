#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(fill_n, Lambda){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v(10000);

  auto it = fill_n(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), v.size(),
              1);

  for(auto i : v){
    EXPECT_EQ(1, v[i]);
  }
  EXPECT_EQ(end(v),it);
}

TEST(fill_n, partial){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v(10000);
  v[8000]=23;
  v[9000]=42;

  auto it = fill_n(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), 8000,
            123);

  EXPECT_EQ(10000, v.size());
  for(auto i=0; i < 8000; i++){
    EXPECT_EQ(123, v[i]);
  }
  EXPECT_EQ(next(begin(v),8000),it);
  EXPECT_EQ(42, v[9000]);
  EXPECT_EQ(23, v[8000]);
}


TEST(fill_n, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  auto it = fill_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  begin(v), 0,
                  1);

  EXPECT_TRUE(v.empty());
  EXPECT_EQ(begin(v),it);
}


TEST(fill_n, Negative){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v(100);

  auto it = fill_n(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  begin(v), -100,
                  1);

  EXPECT_EQ(begin(v),it);
  for(auto i : v){
    EXPECT_EQ(0, v[i]);
  }
}


