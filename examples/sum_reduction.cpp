#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include <experimental/numeric>

// This should be converted to a dynamic policy when they are implemented
template<typename T>
auto sum_reduction(T && policy, const std::vector<double> & values)
  -> std::chrono::microseconds
{
  using namespace std;
  using namespace std::experimental; 

  auto start = chrono::high_resolution_clock::now();
  auto sum = reduce(policy, begin(values), end(values));
  auto finish = chrono::high_resolution_clock::now();

  cout << "sum = " << sum << endl;

  return chrono::duration_cast<chrono::microseconds>(finish-start); 
}

int main()
{
  using namespace std;

  vector<double> values(5000000);
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> d(1, 2);

  generate(begin(values), end(values), [&](){ return d(gen); });

  cout << "Using seq: " 
       << sum_reduction(experimental::parallel::seq, values).count() 
       << " us" << endl;

  cout << "Using par: " 
       << sum_reduction(experimental::parallel::par, values).count() 
       << " us" << endl;
}


