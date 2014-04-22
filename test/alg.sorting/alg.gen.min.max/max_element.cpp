#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

//template<class ExecutionPolicy,class ForwardIterator>
//ForwardIterator max_element(ExecutionPolicy &&exec,
//                            ForwardIterator first, ForwardIterator last);
TEST(max_element, Unique) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};

  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(4, distance(v.begin(), max));
  }

  v[2] = 2;
  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(2, distance(v.begin(), max));

  }

  v[0] = 3;
  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(0, distance(v.begin(), max));

  }

}


TEST(max_element, Multiple) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0};

  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(4, distance(v.begin(), max));
  }

  v[2] = v[3] = 2;
  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(2, distance(v.begin(), max));

  }

  v[0] = 3;
  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(0, distance(v.begin(), max));
  }
}


TEST(max_element, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  auto max = max_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v));
  EXPECT_TRUE(max == end(v));
}

//template<class ExecutionPolicy, class ForwardIterator, class Compare>
//ForwardIterator max_element(ExecutionPolicy &&exec,
//                            ForwardIterator first, ForwardIterator last, Compare comp);
TEST(max_element, CompUnique) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0};

  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(4, distance(v.begin(), max));
  }

  v[2] = -2;
  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(2, distance(v.begin(), max));

  }

  v[0] = -3;
  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(0, distance(v.begin(), max));

  }

}


TEST(max_element, CompMultiple) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,0,0,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0};

  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(4, distance(v.begin(), max));
  }

  v[2] = v[3] = -2;
  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(2, distance(v.begin(), max));

  }

  v[0] = -3;
  {
    auto max = max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(0, distance(v.begin(), max));
  }
}


TEST(max_element, CompEmpty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  auto max = max_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v),
                              greater<int>());
  EXPECT_TRUE(max == end(v));
}


