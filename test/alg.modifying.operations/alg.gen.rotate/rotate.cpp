#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

TEST(rotate, MoveToLast)
{
  using namespace std;
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> gold{2,3,4,5,6,7,8,9,10,11,12,1};

  rotate(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), begin(v)+1, end(v));

  EXPECT_EQ(gold, v);
}

TEST(rotate, MoveRangeToEnd)
{
  using namespace std;
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> gold{7,8,9,10,11,12,1,2,3,4,5,6};

  auto middle = [](vector<int>& v) {
    return begin(v) + v.size()/2;
  };

  rotate(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), middle(v), end(v));

  EXPECT_EQ(gold, v);
}

TEST(rotate, MoveRangeToMiddle)
{
  using namespace std;
  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> gold{4,5,6,1,2,3,7,8,9,10,11,12};

  auto middle = [](vector<int>& v) {
    return begin(v) + v.size()/2;
  };

  auto quarter = [](vector<int>& v) {
    return begin(v) + v.size()/4;
  };

  rotate(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), quarter(v), middle(v));

  EXPECT_EQ(gold, v);
}

TEST(rotate, Empty)
{
  using namespace std;
  vector<int> v;

  rotate(
#ifdef EXECUTION_POLICY
      EXECUTION_POLICY,
#endif
      begin(v), begin(v), end(v));

  EXPECT_TRUE(v.empty());
}
