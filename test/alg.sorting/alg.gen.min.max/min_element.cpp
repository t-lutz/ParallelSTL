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
  std::vector<int> v{0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0};

  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(4, std::distance(v.begin(), min));
  }

  v[2] = -2;
  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(2, std::distance(v.begin(), min));

  }

  v[0] = -3;
  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(0, std::distance(v.begin(), min));

  }

}


TEST(min_element, Multiple) {
  std::vector<int> v{0,0,0,0,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0};

  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(4, std::distance(v.begin(), min));
  }

  v[2] = v[3] = -2;
  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(2, std::distance(v.begin(), min));

  }

  v[0] = -3;
  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(0, std::distance(v.begin(), min));
  }
}


TEST(min_element, Empty){
  std::vector<int> v;

  auto min = std::min_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              std::begin(v), std::end(v));
  EXPECT_TRUE(min == std::end(v));
}

//template<class ExecutionPolicy, class ForwardIterator, class Compare>
//ForwardIterator min_element(ExecutionPolicy &&exec,
//                            ForwardIterator first, ForwardIterator last, Compare comp);
TEST(min_element, CompUnique) {
  std::vector<int> v{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};

  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(4, std::distance(v.begin(), min));
  }

  v[2] = 2;
  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(2, std::distance(v.begin(), min));

  }

  v[0] = 3;
  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(0, std::distance(v.begin(), min));

  }

}


TEST(min_element, CompMultiple) {
  std::vector<int> v{0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0};

  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(4, std::distance(v.begin(), min));
  }

  v[2] = v[3] = 2;
  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(2, std::distance(v.begin(), min));

  }

  v[0] = 3;
  {
    auto min = std::min_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(0, std::distance(v.begin(), min));
  }
}


TEST(min_element, CompEmpty){
  std::vector<int> v;

  auto min = std::min_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              std::begin(v), std::end(v),
                              std::greater<int>());
  EXPECT_TRUE(min == std::end(v));
}


