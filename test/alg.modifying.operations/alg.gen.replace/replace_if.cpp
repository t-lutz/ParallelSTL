#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(replace_if, EvenWithNew)
{
  using namespace std;
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> gold{1,0,3,0,5,0,7,0,9,0,11,0};
  auto even = [](int i) { return (i % 2) == 0; };
  int newVal = 0;

  replace_if(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), end(v), even, newVal);

  EXPECT_EQ(gold, v);
}

TEST(replace_if, Missing)
{
  using namespace std;
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> gold{1,2,3,4,5,6,7,8,9,10,11,12};
  auto isNull = [](int i) { return i == 0; };
  int newVal = 0;

  replace_if(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), end(v), isNull, newVal);

  EXPECT_EQ(gold, v);
}

TEST(replace_if, Empty)
{
  using namespace std;
  vector<int> v;
  auto func = [](int i) { return true; };
  int newVal = 1;

  replace_if(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), end(v), func, newVal);

  EXPECT_TRUE(v.empty());
}
