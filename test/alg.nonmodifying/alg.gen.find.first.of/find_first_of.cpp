#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(find_first_of, Present_unique){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{8,27,42};
  
  auto elt = find_first_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(7, distance(v1.begin(), elt));
}

TEST(find_first_of, Present_unique_first){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{8,27,1};
  
  auto elt = find_first_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(0, distance(v1.begin(), elt));
}

TEST(find_first_of, Present_unique_last){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{12,27,42};
  
  auto elt = find_first_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(11, distance(v1.begin(), elt));
}

TEST(find_first_of, Present_multiple){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{2,3,4};
  
  auto elt = find_first_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(1, distance(v1.begin(), elt));
}

TEST(find_first_of, Present_none){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{42,43,44};
  
  auto elt = find_first_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(end(v1), elt);
}

TEST(find_first_of, Empty_needle){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> v2{};
  
  auto elt = find_first_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(end(v1), elt);
}

TEST(find_first_of, Empty_haystack){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  const vector<int> v1{};
  const vector<int> v2{2,3,4};
  
  auto elt = find_first_of(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v1), end(v1), begin(v2), end(v2));

  EXPECT_EQ(end(v1), elt);
}
