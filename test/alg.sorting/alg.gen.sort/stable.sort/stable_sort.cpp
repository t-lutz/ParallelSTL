#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(stable_sort, PlainSort){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v{1,4,8,7,2,1,5,4,6,5,7,2,5,1,0};

  stable_sort(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}

TEST(stable_sort, Sorted){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v{1,2,3,4,5,6,7,8,9,10};

  stable_sort(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}


TEST(stable_sort, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v;

  stable_sort(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}

TEST(stable_sort, StableSortComp){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<double> v{9.0, 8.5, 8.0, 7.75, 7.5, 7.25, 7.0, 6.5, 6.0, 5.5, 5.0};

  stable_sort(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), end(v),
              [](const double &a, const double &b){
                 return (int)a < (int)b;
              });

  EXPECT_TRUE(is_sorted(begin(v), end(v),
              [](const double &a, const double &b) {
                return (int)a < (int)b || ((int)a == (int)b && a > b);
              }));
}

TEST(stable_sort, Sortable){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  struct Sortable {
    int payload;
    bool operator < (const Sortable &other) const {
      return payload > other.payload;
    }
  };

  vector<Sortable> v{{1}, {3}, {2}, {6}, {4}, {5}};

  stable_sort(
#ifdef EXECUTION_POLICY
              EXECUTION_POLICY,
#endif
              begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}

