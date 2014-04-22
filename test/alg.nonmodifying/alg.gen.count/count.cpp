#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(count, None){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     count(
#ifdef EXECUTION_POLICY
           EXECUTION_POLICY,
#endif
           begin(v), end(v),
           20);

  EXPECT_EQ(0, value); 
}

TEST(count, One){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     count(
#ifdef EXECUTION_POLICY
           EXECUTION_POLICY,
#endif
           begin(v), end(v),
           1);

  EXPECT_EQ(1, value); 
}

TEST(count, Many){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,1,7,8,9,10,1,1};

  auto value = 
     count(
#ifdef EXECUTION_POLICY
           EXECUTION_POLICY,
#endif
           begin(v), end(v),
           1);

  EXPECT_EQ(4, value); 
}

TEST(count, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  auto value = 
     count(
#ifdef EXECUTION_POLICY
           EXECUTION_POLICY,
#endif
           begin(v), end(v),
           1);

  EXPECT_EQ(0, value); 
}

