#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(search_n, Present_unique){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{1,1,2,2,2,3,3,3,4,4,5,5};
  const int needle = 4;
  const size_t count = 2;

  auto elt = search_n(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v), count, needle);

  EXPECT_EQ(8, distance(begin(v), elt));
}

TEST(search_n, Present_unique_fist){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{1,1,2,2,2,3,3,3,4,4,5,5};
  const int needle = 1;
  const size_t count = 2;

  auto elt = search_n(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v), count, needle);

  EXPECT_EQ(0, distance(begin(v), elt));
}

TEST(search_n, Present_unique_last){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{1,1,2,2,2,3,3,3,4,4,5,5};
  const int needle = 5;
  const size_t count = 2;

  auto elt = search_n(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v), count, needle);

  EXPECT_EQ(10, distance(begin(v), elt));
}

TEST(search_n, Present_multiple){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{1,1,2,2,2,3,3,3,4,4,5,5};
  const int needle = 4;
  const size_t count = 3;

  auto elt = search_n(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v), count, needle,
                          [](const int a, const int b){return (a<b);});

  EXPECT_EQ(0, distance(begin(v), elt));
}

TEST(search_n, Missing){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{1,1,2,2,2,3,3,3,4,4,5,5};
  const int needle = 4;
  const size_t count = 3;

  auto elt = search_n(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v), count, needle);

  EXPECT_EQ(end(v), elt);
}

TEST(search_n, Empty_haystack){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{};
  const int needle = 4;
  const size_t count = 2;

  auto elt = search_n(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v), count, needle);

  EXPECT_EQ(end(v), elt);
}

TEST(search_n, Zero_repititions){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{1,1,2,2,2,3,3,3,4,4,5,5};
  const int needle = 4;
  const size_t count = 0;

  auto elt = search_n(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v), count, needle);

  EXPECT_EQ(begin(v), elt);
}

TEST(search_n, Too_many_repititions){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  const vector<int> v{1,1,2,2,2,3,3,3,4,4,5,5};
  const int needle = 4;
  const size_t count = 42;

  auto elt = search_n(
#ifdef EXECUTION_POLICY
                          EXECUTION_POLICY,
#endif
                          begin(v), end(v), count, needle);

  EXPECT_EQ(end(v), elt);
}
