#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(find_end, Present_unique){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{8,9,10};

  auto elt = find_end(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(7, distance(v1.begin(), elt));
}

TEST(find_end, Present_multiple){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{9,8,7};

  auto elt = find_end(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2),
                          [](const int &i1, const int &i2){return (i1<i2);});

  EXPECT_EQ(3, distance(v1.begin(), elt));
}

TEST(find_end, Missing){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{8,9,11};

  auto elt = find_end(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(v1.end(), elt);
}

TEST(find_end, invalid){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{8,9,10};

  auto elt = find_end(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          end(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(v1.end(), elt);
  
  elt = find_end(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), begin(v2));

  EXPECT_EQ(v1.end(), elt);

  elt = find_end(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v2), end(v2), begin(v1), end(v1));

  EXPECT_EQ(v2.end(), elt);
}


