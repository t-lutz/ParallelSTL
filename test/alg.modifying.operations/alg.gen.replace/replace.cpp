#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(replace, OldWithNew)
{
  using namespace std;
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> gold{1,2,3,4,0,6,7,8,9,10,11,12};
  int oldVal = 5;
  int newVal = 0;

  replace(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), end(v), oldVal, newVal);

  EXPECT_EQ(gold, v);
}

TEST(replace, Missing)
{
  using namespace std;
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> gold{1,2,3,4,5,6,7,8,9,10,11,12};
  int oldVal = 0;
  int newVal = 0;

  replace(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), end(v), oldVal, newVal);

  EXPECT_EQ(gold, v);
}

TEST(replace, Empty)
{
  using namespace std;
  vector<int> v;
  int oldVal = 0;
  int newVal = 1;

  replace(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), end(v), oldVal, newVal);

  EXPECT_TRUE(v.empty());
}
