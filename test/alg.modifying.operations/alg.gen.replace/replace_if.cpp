#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

<<<<<<< HEAD
TEST(replace_if, Present_unique){
        std::vector<int> v{1,2,3,4,5,6, 7,8,9,10,11,12};
  const std::vector<int> g{1,2,3,4,5,6,77,8,9,10,11,12};

  std::replace_if(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), std::end(v),
                  [](const int &i) { return i == 7;} , 77);

  EXPECT_EQ(g, v); 
=======
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
>>>>>>> 4c787d8c248baec16899eac1ff8d253e022a5e61
}

TEST(replace_if, Present_multiple){
        std::vector<int> v{1,2,3,4,5,6, 7,8,9,10, 7, 7};
  const std::vector<int> g{1,2,3,4,5,6,77,8,9,10,77,77};

  std::replace_if(
#ifdef EXECUTION_POLICY
                  EXECUTION_POLICY,
#endif
                  std::begin(v), std::end(v),
                  [](const int &i) { return i == 7;}, 77);

  EXPECT_EQ(g, v); 
}

TEST(replace_if, Missing){
        std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const std::vector<int> g{1,2,3,4,5,6,7,8,9,10,11,12};

  std::replace_if(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 [](const int &i) { return i == 20;}, 0);

  EXPECT_EQ(g, v); 
}

TEST(replace_if, Empty){
  std::vector<int> v, g;

  std::replace_if(
#ifdef EXECUTION_POLICY
                 EXECUTION_POLICY,
#endif
                 std::begin(v), std::end(v),
                 [](const int &i) { return true;}, 1);

  EXPECT_EQ(g, v); 
}

