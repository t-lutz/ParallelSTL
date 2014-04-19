#include <iostream>
#include <vector>
#include <memory>

/* -----8<-----8<-----8<-----8<-----8<-----8<-----8<-----8<-----8<-----8<-----8<----- */
/* This part is standard definition; is should not contain user defined types */ 

namespace std {
namespace experimental {
namespace parallel {

// Execution policies
/***********************************************/
class sequential_execution_policy {};
class parallel_execution_policy {};
class execution_policy;
constexpr sequential_execution_policy seq;
constexpr parallel_execution_policy par;

template<class T> struct is_execution_policy
  : public integral_constant<bool, is_base_of<sequential_execution_policy, typename decay<T>::type>::value || 
                                   is_base_of<parallel_execution_policy, typename decay<T>::type>::value || 
                                   is_base_of<execution_policy, typename decay<T>::type>::value > { };

namespace detail {
template<class T, class U> struct __enable_if_parallel_alg_helper
  : public enable_if<is_base_of<sequential_execution_policy, typename std::decay<T>::type>::value ||
                     is_base_of<parallel_execution_policy, typename std::decay<T>::type>::value ||
                     is_base_of<execution_policy, typename std::decay<T>::type>::value,
                     U> { };
}

class execution_policy {
  shared_ptr<void> _instance;
  const type_info *_type;

public:
  template<class ExecutionPolicy>
  execution_policy(const ExecutionPolicy& policy, 
                   typename enable_if<is_execution_policy<ExecutionPolicy>::value,ExecutionPolicy>::type* = nullptr)
  {
    _instance = std::make_shared<ExecutionPolicy>(policy);
    _type = &typeid(ExecutionPolicy);
  }

  template<class ExecutionPolicy>
  typename std::enable_if<is_execution_policy<ExecutionPolicy>::value, execution_policy>::type& 
  operator=(const ExecutionPolicy & policy)
  {
    _instance = std::make_shared<ExecutionPolicy>(policy);
    _type = &typeid(policy);
    return *this;
  }

  const type_info& type() const { return *_type; }
  
  template<class ExecutionPolicy>
  ExecutionPolicy* get() const
  {
    if (*_type != typeid(ExecutionPolicy)) return nullptr;
    return static_cast<ExecutionPolicy*>(_instance.get());
  }
};



// Algorithms
/***********************************************/
template<class RandomAccessIterator>
inline void sort(const sequential_execution_policy &, RandomAccessIterator, RandomAccessIterator)
{
  cout << "sequential_execution_policy" << endl;
}

template<class RandomAccessIterator>
inline void sort(const parallel_execution_policy &, RandomAccessIterator, RandomAccessIterator)
{
  cout << "parallel_execution_policy" << endl;
}

template<class RandomAccessIterator>
inline void sort(const execution_policy &policy, RandomAccessIterator first, RandomAccessIterator last)
{
  if(policy.get<sequential_execution_policy>()){
    sort(*policy.get<sequential_execution_policy>(), first, last);
  }
  else if(policy.get<parallel_execution_policy>()){
    sort(*policy.get<parallel_execution_policy>(), first, last);
  }
  else {
    // TODO: ???
  }
}

template<class ExecutionPolicy,
         class RandomAccessIterator>
inline typename detail::__enable_if_parallel_alg_helper<ExecutionPolicy, void>::type
  sort(ExecutionPolicy &&exec,
       RandomAccessIterator first, RandomAccessIterator last)
{
  sort<RandomAccessIterator>(exec, first, last);
}

}}} // std::experimental::parallel


/* -----8<-----8<-----8<-----8<-----8<-----8<-----8<-----8<-----8<-----8<-----8<----- */

// User code

struct MyPolicy {};

namespace std {
namespace experimental {
namespace parallel {

template<> struct is_execution_policy<MyPolicy> : true_type{};

template<class RandomAccessIterator>
inline void sort(const MyPolicy &, RandomAccessIterator, RandomAccessIterator)
{
  cout << "my clever sort" << endl;
}

}}} // std::experimental::parallel




int main(){
  using namespace std;
  using namespace std::experimental::parallel;
  vector<int> v(10);
  
  MyPolicy policy;

  sort(seq, begin(v), end(v));    // this works
  sort(par, begin(v), end(v));    // this works
  sort(policy, begin(v), end(v)); // this works

  // using execution_policy
  execution_policy dyn = seq;
  sort(dyn, begin(v), end(v)); // this works

  dyn = par;
  sort(dyn, begin(v), end(v)); // this works
  
  dyn = policy;
  sort(dyn, begin(v), end(v)); // this breaks...
}


