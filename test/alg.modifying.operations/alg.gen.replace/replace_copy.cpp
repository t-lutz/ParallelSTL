#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(replace_copy, OldWithNew)
{
  using namespace std;
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  vector<int> v2; v2.resize(v1.size());
  const vector<int> gold{1,2,3,4,0,6,7,8,9,10,11,12};
  int oldVal = 5;
  int newVal = 0;

  replace_copy(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), end(v1), begin(v2), oldVal, newVal);

  EXPECT_EQ(gold, v2);
}

TEST(replace_copy, Missing)
{
  using namespace std;
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  vector<int> v2; v2.resize(v1.size());
  const vector<int> gold{1,2,3,4,5,6,7,8,9,10,11,12};
  int oldVal = 0;
  int newVal = 0;

  replace_copy(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), end(v1), begin(v2), oldVal, newVal);

  EXPECT_EQ(gold, v2);
}

TEST(replace_copy, Empty)
{
  using namespace std;
  const vector<int> v1;
  vector<int> v2;
  int oldVal = 0;
  int newVal = 1;

  replace_copy(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), end(v1), begin(v2), oldVal, newVal);

  EXPECT_TRUE(v2.empty());
}
