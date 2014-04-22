#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

//template<class ExecutionPolicy,
//class RandomAccessIterator>
//  void sort(ExecutionPolicy &&exec,
//    RandomAccessIterator first, RandomAccessIterator last);
TEST(sort, Presorted) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}


TEST(sort, Reverse) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v{12,11,10,9,8,7,6,5,4,3,2,1};

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}


TEST(sort, Random) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v{8,3,6,9,4,12,2,10,1,5,11,2,7};

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}

TEST(sort, Doubles) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v{1,2,2,1,3,4,3,4,1,1,3,5};

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}


TEST(sort, LargeArray) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v(10000);

  fill(begin(v), end(v), rand());

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}


TEST(sort, Empty) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v;

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v));

  EXPECT_TRUE(is_sorted(begin(v), end(v)));
}

//template<class ExecutionPolicy,
//class RandomAccessIterator, class Compare>
//  void sort(ExecutionPolicy &&exec,
//    RandomAccessIterator first, RandomAccessIterator last, Compare comp);
TEST(sort, CompPresorted) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v),
            greater<int>());

  EXPECT_TRUE(is_sorted(begin(v), end(v), greater<int>()));
}


TEST(sort, CompReverse) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v{12,11,10,9,8,7,6,5,4,3,2,1};

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v),
            greater<int>());

  EXPECT_TRUE(is_sorted(begin(v), end(v), greater<int>()));
}


TEST(sort, CompRandom) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v{8,3,6,9,4,12,2,10,1,5,11,2,7};

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v),
            greater<int>());

  EXPECT_TRUE(is_sorted(begin(v), end(v), greater<int>()));
}

TEST(sort, CompDoubles) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v{1,2,2,1,3,4,3,4,1,1,3,5};

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v),
            greater<int>());

  EXPECT_TRUE(is_sorted(begin(v), end(v), greater<int>()));
}


TEST(sort, CompLargeArray) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v(10000);

  fill(begin(v), end(v), rand());

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v),
            greater<int>());

  EXPECT_TRUE(is_sorted(begin(v), end(v),greater<int>()));
}


TEST(sort, CompEmpty) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
    vector<int> v;

  sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            begin(v), end(v),greater<int>());

  EXPECT_TRUE(is_sorted(begin(v), end(v),greater<int>()));
}



