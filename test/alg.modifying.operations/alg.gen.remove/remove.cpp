#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(remove, Present_unique){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> g{1,2,3,4,5,6,  8,9,10,11,12};

  auto range = 
    remove(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 begin(v), end(v),
                 7);

  EXPECT_EQ(distance(g.begin(), g.end()), distance(v.begin(), range)); 
  EXPECT_TRUE(equal(v.begin(), range, g.begin()));
}

TEST(remove, Present_multiple){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,7,7};
  const vector<int> g{1,2,3,4,5,6,  8,9,10    };

  auto range =
     remove(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 begin(v), end(v),
                 7);

  EXPECT_EQ(distance(g.begin(), g.end()), distance(v.begin(), range));
  EXPECT_TRUE(equal(v.begin(), range, g.begin()));
}

TEST(remove, Missing){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> g{1,2,3,4,5,6,7,8,9,10,11,12};

  auto range =
     remove(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 begin(v), end(v),
                 20);

  EXPECT_EQ(distance(g.begin(), g.end()), distance(v.begin(), range));
  EXPECT_TRUE(equal(v.begin(), range, g.begin()));
}

TEST(remove, Empty){
using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v, g;

  auto range =
     remove(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 begin(v), end(v),
                 0);

  EXPECT_EQ(distance(g.begin(), g.end()), distance(v.begin(), range));
  EXPECT_TRUE(equal(v.begin(), range, g.begin()));
}

