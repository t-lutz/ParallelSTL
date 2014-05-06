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

}}}


// Usage example
// *************
int main()
{
  using namespace std::experimental;
  using namespace std;

  vector<int> v;
  parallel::execution_policy exec = parallel::seq;

  // try the standard methods first
  cout << "Sorting using std::parallel::seq:" << endl;
  parallel::sort(exec, std::begin(v), std::end(v)); // doesn't print anything
  cout << "done" << endl << endl; 
 
  exec = parallel::par;
  cout << "Sorting using std::parallel::par:" << endl;
  parallel::sort(exec, std::begin(v), std::end(v)); // doesn't print anything
  cout << "done" << endl << endl;

  // try valid user policies
  exec = SortA{};
  cout << "Sorting using my sort A:" << endl;
  parallel::sort(exec, std::begin(v), std::end(v)); // prints ">> SortA is sorting..."
  cout << "done" << endl << endl;

  exec = SortB{};
  cout << "Sorting using my sort B:" << endl;
  parallel::sort(exec, std::begin(v), std::end(v)); // prints ">> SortB is sorting..."
  cout << "done" << endl << endl;

  // try invalid user policy (does not define sort)
  try {
    exec = NoSort{};
    cout << "Sorting using a policy which does not support sort:" << endl;
    parallel::sort(exec, std::begin(v), std::end(v)); // this throws since NoSort does not define sort
    cout << "done" << endl << endl;
  }
  catch(std::invalid_argument e){
    cout << "exception: " << e.what() << endl << endl;
  }

  exec = DefaultedSort{};
  cout << "Sorting using a policy with a default sort:" << endl;
  parallel::sort(exec, std::begin(v), std::end(v));
  cout << "done" << endl;
}


