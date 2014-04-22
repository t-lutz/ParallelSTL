#include <vector>
#include <iostream>
#include <chrono>
#include <atomic>
#include <random>
#include <experimental/algorithm>

// This should be converted to a dynamic policy when they are implemented
template<typename T>
auto sort(T && policy, const std::vector<unsigned> & values)
  -> std::chrono::microseconds
{
  using namespace std;
  using namespace std::experimental; 

  auto copy = values;

  auto start = chrono::high_resolution_clock::now();
  sort(policy, begin(copy), end(copy));
  auto finish = chrono::high_resolution_clock::now();

  cout << "Is sorted: " << boolalpha << is_sorted(begin(copy), end(copy)) << endl;

  return chrono::duration_cast<chrono::microseconds>(finish-start); 
}

int main(){
  using namespace std;

  vector<unsigned> values(5000000);
  random_device rd;
  mt19937 gen(rd());
  poisson_distribution<> d(10000);

  generate(begin(values), end(values), [&](){ return d(gen); });
  cout << "Is sorted: " << boolalpha << is_sorted(begin(values), end(values)) << endl;

  cout << "Using seq: " << endl;
  auto time_seq = sort(experimental::parallel::seq, values);
  cout << "seq took " << time_seq.count() << " us" << endl;

  cout << "Using par: " << endl;
  auto time_par = sort(experimental::parallel::par, values);
  cout << "par took " << time_par.count() << " us" << endl;
}

