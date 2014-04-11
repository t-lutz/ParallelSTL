#include "gtest/gtest.h"

#include <vector>
#include <cstdlib>

#ifdef EXECUTION_POLICY
#include <experimental/utility>
#else
// this function is not in the standard
#include <experimental/utility>
#endif

//template<class InputIterator>
//  typename iterator_traits<InputIterator>::value_type
//    reduce(InputIterator first, InputIterator last);
//template<class ExecutionPolicy, class InputIterator>
//  typename iterator_traits<InputIterator>::value_type
//    reduce(ExecutionPolicy &&exec,
//           InputIterator first, InputIterator last);
TEST(reduce, IntNoInit){
  const std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::end(v));

  EXPECT_EQ(78, res);
}


TEST(reduce, CustomNoInit){
  struct Element {
    int value;
    Element(int i) : value{i} {}
    Element() : value{1} {}
    Element operator+(const Element &other){
      return {value + other.value};
    }
  };
  
  // unititialized elements are 1, reduction should be 100
  const std::vector<Element> v(100);

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::end(v));

  EXPECT_EQ(100, res.value);
}


TEST(reduce, IntNoInitEmptyRange){
  const std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::begin(v));

  EXPECT_EQ(0, res);
}



TEST(reduce, CustomNoInitEmptyRange){
  struct Element {
    int value;
    Element(int i) : value{i} {}
    Element() : value{1} {}
    Element operator+(const Element &other){
      return {value + other.value};
    }
  };
  
  const std::vector<Element> v{
    {2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12},{13}
  };

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::begin(v));

  // should return Element{0}
  EXPECT_EQ(0, res.value);
}


//template<class InputIterator, class T>
//    T reduce(InputIterator first, InputIterator last, T init);
//  template<class ExecutionPolicy,
//           class InputIterator, class T>
//    T reduce(ExecutionPolicy &&exec,
//             InputIterator first, InputIterator last, T init);
TEST(reduce, IntInit){
  const std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::end(v), 10);

  EXPECT_EQ(88, res);
}


TEST(reduce, CustomInit){
  struct Element {
    int value;
    Element(int i) : value{i} {}
    Element() : value{1} {}
    Element operator+(const Element &other){
      return {value + other.value};
    }
  };
  
  // unititialized elements are 1, reduction should be 100
  const std::vector<Element> v(100);

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::end(v), Element{100});

  EXPECT_EQ(200, res.value);
}


TEST(reduce, IntInitEmptyRange){
  const std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::begin(v), 10);

  EXPECT_EQ(10, res);
}



TEST(reduce, CustomInitEmptyRange){
  struct Element {
    int value;
    Element(int i) : value{i} {}
    Element() : value{1} {}
    Element operator+(const Element &other){
      return {value + other.value};
    }
  };
  
  const std::vector<Element> v{
    {2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12},{13}
  };

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::begin(v), Element{10});

  // should return Element{10}
  EXPECT_EQ(10, res.value);
}


//template<class InputIterator, class T, class BinaryOperation>
//  T reduce(InputIterator first, InputIterator last, T init,
//           BinaryOperation binary_op);
//template<class ExecutionPolicy,
//         class InputIterator, class T, class BinaryOperation>
//  T reduce(ExecutionPolicy &&exec,
//           InputIterator first, InputIterator last, T init,
//           BinaryOperation binary_op);
TEST(reduce, IntInitBinary){
  const std::vector<int> v{2, 4, 3, 1, 5, 2, 3};
  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::end(v), 1,
                         [](const int &i, const int &j) { 
                            return i*j; 
                         });

  EXPECT_EQ(720, res);

  res = std::reduce(
#ifdef EXECUTION_POLICY
                    EXECUTION_POLICY,
#endif
                    std::begin(v), std::end(v), 0,
                    [](const int &i, const int &j) { 
                       return i*j; 
                    }); 

  EXPECT_EQ(0, res);
}


TEST(reduce, CustomInitBinary){
  struct Element {
    int value;
    Element(int i) : value{i} {}
    Element() : value{1} {}
  };
  
  // unititialized elements are 1, reduction should be 100
  const std::vector<Element> v{{2}, {4}, {3}, {1}, {5}, {2}, {3}};

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::end(v), Element{100},
                         [](const Element a, const Element &b)->Element{
                            return {a.value * b.value};
                         });

  EXPECT_EQ(72000, res.value);
}


TEST(reduce, IntInitEmptyRangeBinary){
  const std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12};

  auto res = std::reduce(
#ifdef EXECUTION_POLICY
                         EXECUTION_POLICY,
#endif
                         std::begin(v), std::begin(v), 1,
                         [](const int &i, const int &j) {          
                            return i*j;          
                         });

  EXPECT_EQ(1, res);
}

