#include "gtest/gtest.h"

#include <vector>

#ifdef EXECUTION_POLICY
#include <experimental/algorithm>
#else
#include <algorithm>
#endif

//template<class ExecutionPolicy,class ForwardIterator>
//ForwardIterator minmax_element(ExecutionPolicy &&exec,
//                            ForwardIterator first, ForwardIterator last);
TEST(minmax_element, Unique) 
{
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace experimental; 
#endif
  
  vector<int> v{0,0,0,0,1,0,-1,0,0,0,0,0,0,0,0,0};

  {
    auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                                 EXECUTION_POLICY,
#endif
                                 begin(v), end(v));

    EXPECT_EQ(6, distance(begin(v), minmax.first));
    EXPECT_EQ(4, distance(begin(v), minmax.second));
  }

  v[2] = 2;
  v[8] = -2;
  {
    auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                                 EXECUTION_POLICY,
#endif
                                 begin(v), end(v));

    EXPECT_EQ(8, distance(begin(v), minmax.first));
    EXPECT_EQ(2, distance(begin(v), minmax.second));

  }
}


TEST(minmax_element, Multiple) 
{
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,-1,0,1,1,1,1,1,1,-1,-1,0,0,0,0};

  {
    auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                                 EXECUTION_POLICY,
#endif
                                 begin(v), end(v));

    EXPECT_EQ(2, distance(begin(v), minmax.first));
    EXPECT_EQ(9, distance(begin(v), minmax.second));
  }

  v[2] = v[4] = 2;
  v[1] = v[5] = -2;
  {
    auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                                 EXECUTION_POLICY,
#endif
                                 begin(v), end(v));

    
    EXPECT_EQ(1, distance(begin(v), minmax.first));
    EXPECT_EQ(4, distance(begin(v), minmax.second));

  }
}

TEST(minmax_element, AllSame) 
{
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace experimental;
#endif
  
  vector<int> v{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                               EXECUTION_POLICY,
#endif
                               begin(v), end(v));

  EXPECT_EQ(minmax.first, begin(v)); 
  EXPECT_EQ(v.size()-1, distance(begin(v), minmax.second));
}



TEST(minmax_element, Empty){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v));
  EXPECT_TRUE(minmax.first == end(v));
  EXPECT_TRUE(minmax.second == end(v));
}

//template<class ExecutionPolicy, class ForwardIterator, class Compare>
//ForwardIterator minmax_element(ExecutionPolicy &&exec,
//                            ForwardIterator first, ForwardIterator last, Compare comp);
TEST(minmax_element, UniqueComp) 
{
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v{0,0,0,0,1,0,-1,0,0,0,0,0,0,0,0,0};

  {
    auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                                 EXECUTION_POLICY,
#endif
                                 begin(v), end(v), greater<int>());

    EXPECT_EQ(4, distance(begin(v), minmax.first));
    EXPECT_EQ(6, distance(begin(v), minmax.second));
  }

  v[2] = 2;
  v[8] = -2;
  {
    auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                                 EXECUTION_POLICY,
#endif
                                 begin(v), end(v), greater<int>());

    EXPECT_EQ(2, distance(begin(v), minmax.first));
    EXPECT_EQ(8, distance(begin(v), minmax.second));

  }
}


TEST(minmax_element, MultipleComp) 
{
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace experimental;
#endif
  
  vector<int> v{0,0,-1,0,1,1,1,1,1,1,-1,-1,0,0,0,0};

  {
    auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                                 EXECUTION_POLICY,
#endif
                                 begin(v), end(v), greater<int>());

    EXPECT_EQ(4, distance(begin(v), minmax.first));
    EXPECT_EQ(11, distance(begin(v), minmax.second));
  }

  v[2] = v[3] = 2;
  v[1] = v[5] = -2;
  {
    auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                                 EXECUTION_POLICY,
#endif
                                 begin(v), end(v), greater<int>());

    
    EXPECT_EQ(2, distance(begin(v), minmax.first));
    EXPECT_EQ(5, distance(begin(v), minmax.second));

  }
}

TEST(minmax_element, AllSameComp) 
{
  using namespace std;
#ifdef EXECUTION_POLICY 
  using namespace experimental;
#endif
  
  vector<int> v{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                               EXECUTION_POLICY,
#endif
                               begin(v), end(v), greater<int>());

  EXPECT_EQ(minmax.first, begin(v)); 
  EXPECT_EQ(v.size()-1, distance(begin(v), minmax.second));
}



TEST(minmax_element, EmptyComp){
  using namespace std;
#ifdef EXECUTION_POLICY
  using namespace std::experimental;
#endif
  
  vector<int> v;

  auto minmax = minmax_element(
#ifdef EXECUTION_POLICY
                              EXECUTION_POLICY,
#endif
                              begin(v), end(v), greater<int>());
  EXPECT_TRUE(minmax.first == end(v));
  EXPECT_TRUE(minmax.second == end(v));
}


