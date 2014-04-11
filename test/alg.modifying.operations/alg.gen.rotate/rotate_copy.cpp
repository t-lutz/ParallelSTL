#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(rotate_copy, MoveToLast)
{
  using namespace std;
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  vector<int> v2; v2.resize(v1.size());
  const vector<int> gold{2,3,4,5,6,7,8,9,10,11,12,1};

  rotate_copy(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), begin(v1)+1, end(v1), begin(v2));

  EXPECT_EQ(gold, v2);
}

TEST(rotate_copy, MoveRangeToEnd)
{
  using namespace std;
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  vector<int> v2; v2.resize(v1.size());
  const vector<int> gold{7,8,9,10,11,12,1,2,3,4,5,6};

  auto middle = [](const vector<int>& v) {
    return begin(v) + v.size()/2;
  };

  rotate_copy(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), middle(v1), end(v1), begin(v2));

  EXPECT_EQ(gold, v2);
}

TEST(rotate_copy, MoveRangeToMiddle)
{
  using namespace std;
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  vector<int> v2; v2.resize(v1.size());
  const vector<int> gold{4,5,6,1,2,3,0,0,0,0,0,0};

  auto middle = [](const vector<int>& v) {
    return begin(v) + v.size()/2;
  };

  auto quarter = [](const vector<int>& v) {
    return begin(v) + v.size()/4;
  };

  rotate_copy(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), quarter(v1), middle(v1), begin(v2));

  EXPECT_EQ(gold, v2);
}

TEST(rotate_copy, Empty)
{
  using namespace std;
  const vector<int> v1;
  vector<int> v2;

  rotate_copy(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v1), begin(v1), end(v1), begin(v2));

  EXPECT_TRUE(v2.empty());
}
