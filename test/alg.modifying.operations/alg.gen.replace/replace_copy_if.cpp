#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(replace_copy_if, EvenWithNew)
{
  using namespace std;
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  vector<int> v2; v2.resize(v1.size());
  const vector<int> gold{1,0,3,0,5,0,7,0,9,0,11,0};
  auto even = [](int i) { return (i % 2) == 0; };
  int newVal = 0;

  replace_copy_if(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), end(v1), begin(v2), even, newVal);

  EXPECT_EQ(gold, v2);
}

TEST(replace_copy_if, Missing)
{
  using namespace std;
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  vector<int> v2; v2.resize(v1.size());
  const vector<int> gold{1,2,3,4,5,6,7,8,9,10,11,12};
  auto isNull = [](int i) { return i == 0; };
  int newVal = 0;

  replace_copy_if(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), end(v1), begin(v2), isNull, newVal);

  EXPECT_EQ(gold, v2);
}

TEST(replace_copy_if, Empty)
{
  using namespace std;
  const vector<int> v1;
  vector<int> v2;
  auto func = [](int i) { return true; };
  int newVal = 1;

  replace_copy_if(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), end(v1), begin(v2), func, newVal);

  EXPECT_TRUE(v2.empty());
}
