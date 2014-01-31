#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <parallel/algorithm>
#else
#include <algorithm>
#endif

//template<class ExecutionPolicy,class ForwardIterator>
//ForwardIterator max_element(ExecutionPolicy &&exec,
//                            ForwardIterator first, ForwardIterator last);
TEST(max_element, Unique) {
  std::vector<int> v{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};

  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(4, std::distance(v.begin(), max));
  }

  v[2] = 2;
  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(2, std::distance(v.begin(), max));

  }

  v[0] = 3;
  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(0, std::distance(v.begin(), max));

  }

}


TEST(max_element, Multiple) {
  std::vector<int> v{0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0};

  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(4, std::distance(v.begin(), max));
  }

  v[2] = v[3] = 2;
  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(2, std::distance(v.begin(), max));

  }

  v[0] = 3;
  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v));

    EXPECT_EQ(0, std::distance(v.begin(), max));
  }
}


TEST(max_element, Empty){
  std::vector<int> v;

  auto max = std::max_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              std::begin(v), std::end(v));
  EXPECT_TRUE(max == std::end(v));
}

//template<class ExecutionPolicy, class ForwardIterator, class Compare>
//ForwardIterator max_element(ExecutionPolicy &&exec,
//                            ForwardIterator first, ForwardIterator last, Compare comp);
TEST(max_element, CompUnique) {
  std::vector<int> v{0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0};

  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(4, std::distance(v.begin(), max));
  }

  v[2] = -2;
  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(2, std::distance(v.begin(), max));

  }

  v[0] = -3;
  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(0, std::distance(v.begin(), max));

  }

}


TEST(max_element, CompMultiple) {
  std::vector<int> v{0,0,0,0,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0};

  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(4, std::distance(v.begin(), max));
  }

  v[2] = v[3] = -2;
  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(2, std::distance(v.begin(), max));

  }

  v[0] = -3;
  {
    auto max = std::max_element(
#ifdef EXECUTION_POLICY
                                EXECUTION_POLICY,
#endif
                                std::begin(v), std::end(v),
                                std::greater<int>());

    EXPECT_EQ(0, std::distance(v.begin(), max));
  }
}


TEST(max_element, CompEmpty){
  std::vector<int> v;

  auto max = std::max_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              std::begin(v), std::end(v),
                              std::greater<int>());
  EXPECT_TRUE(max == std::end(v));
}


