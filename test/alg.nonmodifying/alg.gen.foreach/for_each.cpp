#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

TEST(for_each, Double){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};
  const vector<int> golden{2,4,6,8,10,12,14,16,18,20,22,24};

  for_each(
#ifdef EXECUTION_POLICY
           EXECUTION_POLICY,
#endif
           begin(v), end(v),
           [](int &i){ i*= 2; });

  EXPECT_TRUE(v == golden); 
}

TEST(for_each, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  vector<int> v;
  
  for_each(
#ifdef EXECUTION_POLICY
           EXECUTION_POLICY,
#endif
           begin(v), end(v),
           [](int &i){ i = 0; });

  EXPECT_TRUE(v.empty());
}

TEST(for_each, Accumulate) {
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif

  struct Accu {
    unsigned int count;
    unsigned int sum;
    Accu():count{0}, sum{0}{}
    void operator()(int& i) {count++; sum += i;} 
  } Acc;

  vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto res = for_each(
#ifdef EXECUTION_POLICY
                      EXECUTION_POLICY,
#endif
                      begin(v), end(v),
                      Acc);

  EXPECT_EQ(v.size(), res.count);
  EXPECT_EQ(78, res.sum);
}

