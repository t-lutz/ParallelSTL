#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

#ifndef EXECUTION_POLICY
#include <parallel/algorithm>
#endif

//template<class ExecutionPolicy,
//class RandomAccessIterator>
//  void sort(ExecutionPolicy &&exec,
//    RandomAccessIterator first, RandomAccessIterator last);
TEST(sort, Presorted) {
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v));

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v)));
}


TEST(sort, Reverse) {
  std::vector<int> v{12,11,10,9,8,7,6,5,4,3,2,1};

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v));

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v)));
}


TEST(sort, Random) {
  std::vector<int> v{8,3,6,9,4,12,2,10,1,5,11,2,7};

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v));

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v)));
}

TEST(sort, Doubles) {
  std::vector<int> v{1,2,2,1,3,4,3,4,1,1,3,5};

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v));

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v)));
}


TEST(sort, LargeArray) {
  std::vector<int> v(10000);

  std::fill(std::begin(v), std::end(v), std::rand());

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v));

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v)));
}


TEST(sort, Empty) {
  std::vector<int> v;

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v));

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v)));
}

//template<class ExecutionPolicy,
//class RandomAccessIterator, class Compare>
//  void sort(ExecutionPolicy &&exec,
//    RandomAccessIterator first, RandomAccessIterator last, Compare comp);
TEST(sort, CompPresorted) {
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v),
            std::greater<int>());

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v), std::greater<int>()));
}


TEST(sort, CompReverse) {
  std::vector<int> v{12,11,10,9,8,7,6,5,4,3,2,1};

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v),
            std::greater<int>());

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v), std::greater<int>()));
}


TEST(sort, CompRandom) {
  std::vector<int> v{8,3,6,9,4,12,2,10,1,5,11,2,7};

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v),
            std::greater<int>());

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v), std::greater<int>()));
}

TEST(sort, CompDoubles) {
  std::vector<int> v{1,2,2,1,3,4,3,4,1,1,3,5};

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v),
            std::greater<int>());

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v), std::greater<int>()));
}


TEST(sort, CompLargeArray) {
  std::vector<int> v(10000);

  std::fill(std::begin(v), std::end(v), std::rand());

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v),
            std::greater<int>());

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v),std::greater<int>()));
}


TEST(sort, CompEmpty) {
  std::vector<int> v;

  std::sort(
#ifdef EXECUTION_POLICY
            EXECUTION_POLICY,
#endif
            std::begin(v), std::end(v),std::greater<int>());

  EXPECT_TRUE(std::is_sorted(std::begin(v), std::end(v),std::greater<int>()));
}



