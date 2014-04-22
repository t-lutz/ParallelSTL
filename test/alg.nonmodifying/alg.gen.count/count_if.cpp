#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(count_if, None){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     count_if(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), end(v),
              [](const int &i){return i > 20;});

  EXPECT_EQ(0, value); 
}

TEST(count_if, One){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     count_if(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), end(v),
              [](const int &i){return i == 2;});

  EXPECT_EQ(1, value); 
}

TEST(count_if, Many){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto value = 
     count_if(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), end(v),
              [](const int &i){return i < 8;});

  EXPECT_EQ(7, value); 
}

TEST(count_if, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  auto value = 
     count_if(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), end(v),
              [](const int &i){return true;});

  EXPECT_EQ(0, value); 
}

