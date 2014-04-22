#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(for_each_n, Double){
#ifdef EXECUTION_POLICY
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> golden{2,4,6,8,10,6,7,8,9,10,11,12};

  for_each_n(
                EXECUTION_POLICY,
                begin(v), 5,
                [](int &i){ i*= 2; });

  EXPECT_TRUE(v == golden);
#else
  // not in current standard
  EXPECT_TRUE(true);
#endif 
}

TEST(for_each_n, Empty){
#ifdef EXECUTION_POLICY
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;
  
  for_each_n(
                EXECUTION_POLICY,
                begin(v), 0,
                [](int &i){ i = 0; });

  EXPECT_TRUE(v.empty());
#else
  // not in current standard
  EXPECT_TRUE(true);
#endif
}

TEST(for_each_n, Zero){
#ifdef EXECUTION_POLICY
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> golden{1,2,3,4,5,6,7,8,9,10,11,12};
  
  for_each_n(
                EXECUTION_POLICY,
                begin(v), 0,
                [](int &i){ i = -1; });

  EXPECT_TRUE(v == golden);
#else
  // not in current standard
  EXPECT_TRUE(true);
#endif
}




