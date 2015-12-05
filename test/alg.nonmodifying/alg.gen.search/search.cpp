#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(search, Present_unique){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{8,9,10};

  auto elt = search(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(7, distance(begin(v1), elt));
}

TEST(search, Present_unique_fist){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{1,2,3};

  auto elt = search(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(0, distance(begin(v1), elt));
}

TEST(search, Present_unique_last){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{12};

  auto elt = search(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(11, distance(begin(v1), elt));
}

TEST(search, Present_multiple){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{9,8,7};

  auto elt = search(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2),
                          [](const int &i1, const int &i2){return (i1<i2);});

  EXPECT_EQ(0, distance(begin(v1), elt));
}

TEST(search, Missing){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{8,9,11};

  auto elt = search(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(end(v1), elt);
}

TEST(search, Empty_haystack){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1;
  const vector<int> v2{8,9,10};

  auto elt = search(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(end(v1), elt);
}

TEST(search, Empty_needle){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2;

  auto elt = search(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(begin(v1), elt);
}

TEST(search, Needle_bigger_than_haystack){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v2{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v1{8,9,10};

  auto elt = search(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(end(v1), elt);
}
