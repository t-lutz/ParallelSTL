#include "gtest/gtest.h"

#include <algorithm>
#include <vector>

#ifndef EXECUTION_POLICY
#include <parallel/algorithm>
#endif

TEST(for_each, Double){
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const std::vector<int> golden{2,4,6,8,10,12,14,16,18,20,22,24};

  std::for_each(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                std::begin(v), std::end(v),
                [](int &i){ i*= 2; });

  EXPECT_TRUE(v == golden); 
}

TEST(for_each, Empty){
  std::vector<int> v;
  
  std::for_each(
#ifdef EXECUTION_POLICY
                EXECUTION_POLICY,
#endif
                std::begin(v), std::end(v),
                [](int &i){ i = 0; });

  EXPECT_TRUE(v.empty());
}

TEST(for_each, Accumulate) {
  struct Accu {
    unsigned int count;
    unsigned int sum;
    Accu():count{0}, sum{0}{}
    void operator()(int& i) {count++; sum += i;} 
  } Acc;

  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto res = std::for_each(
#ifdef EXECUTION_POLICY
                           EXECUTION_POLICY,
#endif
                           std::begin(v), std::end(v),
                           Acc);

  EXPECT_EQ(v.size(), res.count);
  EXPECT_EQ(78, res.sum);
}

