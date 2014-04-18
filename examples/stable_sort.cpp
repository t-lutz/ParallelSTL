/**
 * Stable sort test. We generate a vector of doubles sorted in descending 
 * order. We then sort this arrays in ascending order using only the integral
 * part. The result is an array where values are sorted in ascending integral 
 * values but descending fractional values.
 */

#include <vector>
#include <iostream>
#include <chrono>
#include <atomic>
#include <random>
#include <experimental/algorithm>

// Compare function to check that integral part is sorted in ascending order and
// fractional part in descending order
bool compare(const double &a, const double &b) {
  return (int)a < (int)b || ((int)a == (int)b && a > b);
}


// This should be converted to a dynamic policy when they are implemented
template<typename T>
auto stable_sort(T && policy, const std::vector<double> & values)
  -> std::chrono::microseconds
{
  using namespace std;
  auto copy = values;

  auto start = chrono::high_resolution_clock::now();
  stable_sort(policy, begin(copy), end(copy), 
              [](const double &a, const double &b){
                return (int)a < (int)b;
              });
  auto finish = chrono::high_resolution_clock::now();

  cout << "Is (partially) sorted: " << boolalpha
       << is_sorted(begin(copy), end(copy), compare) << endl;

  return chrono::duration_cast<chrono::microseconds>(finish-start); 
}

int main(){
  using namespace std;

  double start = 100000;
  std::vector<double> values(5000000);
  generate(begin(values), end(values), [&](){ start -= 0.1; return start; });

  cout << "Is (partially) sorted: " << boolalpha
       << is_sorted(begin(values), end(values),compare) << endl;

  cout << "Using seq: " << endl;
  auto time_seq = stable_sort(experimental::parallel::seq, values);
  cout << "seq took " << time_seq.count() << " us" << endl;
  
  cout << "Using par: " << endl;
  auto time_par = stable_sort(experimental::parallel::par, values);
  cout << "par took " << time_par.count() << " us" << endl;
}

