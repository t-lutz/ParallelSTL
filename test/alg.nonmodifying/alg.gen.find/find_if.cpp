#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(find_if, Present_unique){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto elt = find_if(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v),
                          [](const int&i){return i == 7;});

  EXPECT_EQ(6, distance(v.begin(), elt)); 
}

TEST(find_if, Present_multiple){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v{1,2,3,4,5,6,7,8,9,10,7,7};

  auto elt = find_if(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v),
                          [](const int&i){return i == 7;});

  EXPECT_EQ(6, distance(v.begin(), elt)); 
}

TEST(find_if, Missing){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto elt = find_if(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v),
                          [](const int&i){return i == 20;});

  EXPECT_EQ(v.end(), elt); 
}

TEST(find_if, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v;

  auto elt = find_if(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v),
                          [](const int&i){return true;});

  EXPECT_EQ(v.end(), elt); 
}

