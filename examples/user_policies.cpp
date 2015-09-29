// since a51efe9959 you need c++14 support and to define _bleeding_edge. In gcc 4.9:
// g++ -std=c++1y user_policies.cpp -o up -I../include -lpthread -D_bleeding_edge

#include <iostream>
#include <vector>
#include <experimental/algorithm>
#include <experimental/execution_policy>

// User defined policies
// *********************
struct SortA {
  template<typename RandomIt>
  void sort(RandomIt, RandomIt) const {
    typedef typename std::iterator_traits<RandomIt>::value_type it_type;
    std::cout << ">> SortA is sorting an array of type " << typeid(it_type).name() << std::endl; 
  }
};

struct SortB {
  template<typename RandomIt>
  void sort(RandomIt, RandomIt) const {
    typedef typename std::iterator_traits<RandomIt>::value_type it_type;
    std::cout << ">> SortB is sorting an array of type " << typeid(it_type).name() << std::endl; 
  }

  template<typename RandomIt, class Compare>
  void sort(RandomIt, RandomIt, Compare) const {
    typedef typename std::iterator_traits<RandomIt>::value_type it_type;
    std::cout << ">> SortB is compare-sorting an array of type " << typeid(it_type).name() << std::endl; 
  }
 
};

struct NoSort {
  /* This is an example of policy which does not define sort */
};

struct DefaultedSort : public std::experimental::parallel::sequential_execution_policy {
  // does not define sort, but extends a policy that does
};

// Register policies as valid execution policies
// *********************************************
namespace std {
namespace experimental {
namespace parallel {
inline namespace v1 {

template<> struct is_execution_policy<SortA> : true_type{};
template<> struct is_execution_policy<SortB> : true_type{};
template<> struct is_execution_policy<NoSort> : true_type{};
template<> struct is_execution_policy<DefaultedSort> : true_type{};

// this bit needs to go away. This registers the type to the dispatcher,
// there must be a cleaner way to do this.
namespace details{
template<> struct PolicyRegistry<> { typedef SortA type; };
template<> struct PolicyRegistry<> { typedef SortB type; };
template<> struct PolicyRegistry<> { typedef NoSort type; };
template<> struct PolicyRegistry<> { typedef DefaultedSort type; };
}

}}}}


// Usage example
// *************

// This calls sort using a dynamic policy
void sortMe(std::vector<int> &v, 
            std::experimental::parallel::execution_policy &exec, 
            const std::string &desc)
{
  using namespace std::experimental;
  std::cout << "Sorting using " << desc << ": " << std::endl;
  parallel::sort(exec, std::begin(v), std::end(v));
  std::cout << "done\n\n";
}

int main()
{
  using namespace std::experimental;
  using namespace std;

  vector<int> v;

  // try the standard methods first
  parallel::execution_policy exec = parallel::seq;
  sortMe(v, exec, "std::parallel::seq"); // prints nothing

  exec = parallel::par;
  sortMe(v, exec, "std::parallel::par"); // prints nothing

  // try valid user policies
  exec = SortA{};
  sortMe(v, exec, "my Sort A"); // prints ">> SortA is sorting..."

  exec = SortB{};
  sortMe(v, exec, "my Sort B"); // prints ">> SortB is sorting..."

  // try invalid user policy (does not define sort)
  try {
    exec = NoSort{};
    sortMe(v, exec, "a policy which does not support sort"); // throws an exception
  }
  catch(std::invalid_argument e){
    cout << "exception: " << e.what() << endl << endl;
  }

  // A derived policy works as well
  exec = DefaultedSort{};
  sortMe(v, exec, "a policy with a default sort"); // prints nothing

  // now let's try another sort
  try {
    exec = SortB{};
    std::cout << "Another sort using Sort B" << std::endl;
    parallel::sort(exec, std::begin(v), std::end(v), std::greater<int>()); // prints ">> SortB is compare-sorting..."
    std::cout << "done\n\n";

    exec = SortA{};
    std::cout << "Another sort using Sort A" << std::endl;
    parallel::sort(exec, std::begin(v), std::end(v), std::greater<int>()); // oops, this throws
  } catch(std::invalid_argument e){
    cout << "exception: " << e.what() << endl << endl;
  }
}


