#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

//template<class ExecutionPolicy,class ForwardIterator>
//ForwardIterator min_element(ExecutionPolicy &&exec,
//                            ForwardIterator first, ForwardIterator last);
TEST(min_element, Unique) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0};

  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(4, distance(v.begin(), min));
  }

  v[2] = -2;
  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(2, distance(v.begin(), min));

  }

  v[0] = -3;
  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(0, distance(v.begin(), min));

  }

}


TEST(min_element, Multiple) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,0,0,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0};

  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(4, distance(v.begin(), min));
  }

  v[2] = v[3] = -2;
  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(2, distance(v.begin(), min));

  }

  v[0] = -3;
  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v));

    EXPECT_EQ(0, distance(v.begin(), min));
  }
}


TEST(min_element, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  auto min = min_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v));
  EXPECT_TRUE(min == end(v));
}

//template<class ExecutionPolicy, class ForwardIterator, class Compare>
//ForwardIterator min_element(ExecutionPolicy &&exec,
//                            ForwardIterator first, ForwardIterator last, Compare comp);
TEST(min_element, CompUnique) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};

  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(4, distance(v.begin(), min));
  }

  v[2] = 2;
  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(2, distance(v.begin(), min));

  }

  v[0] = 3;
  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(0, distance(v.begin(), min));

  }

}


TEST(min_element, CompMultiple) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0};

  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(4, distance(v.begin(), min));
  }

  v[2] = v[3] = 2;
  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(2, distance(v.begin(), min));

  }

  v[0] = 3;
  {
    auto min = min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                begin(v), end(v),
                                greater<int>());

    EXPECT_EQ(0, distance(v.begin(), min));
  }
}


TEST(min_element, CompEmpty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  auto min = min_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v),
                              greater<int>());
  EXPECT_TRUE(min == end(v));
}


