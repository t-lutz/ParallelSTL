/*
 * This program computes the histogram of an array of random values.
 *
 * The parallel version of std::for_each requires thread safe access to the counters,
 * so it is using atomics, while the sequential version uses plain ints.
 *
 * We test for high contention on the counters and lower contention.
 */

#include <vector>
#include <iostream>
#include <chrono>
#include <atomic>
#include <random>
#include <experimental/algorithm>

// This should be converted to a dynamic policy when they are implemented
template<typename Counter, typename T>
auto Histogram(T && policy, const std::vector<unsigned> & values, const unsigned max)
  -> std::chrono::microseconds
{
  using namespace std;
  using namespace std::experimental;
  vector<Counter> hist(max);

  auto start = chrono::high_resolution_clock::now();
  for_each(policy, begin(values), end(values), 
      [&hist](const int & value) {
        hist[value]++;
      });
  auto finish = chrono::high_resolution_clock::now();

  for(auto &v : hist) if(v == 5000001) cerr << "impossible" << endl; 

  return chrono::duration_cast<chrono::microseconds>(finish-start); 
}

void test(unsigned hist_size){
  using namespace std;

  vector<unsigned> values(5000000);
  random_device rd;
  mt19937 gen(rd());
  poisson_distribution<> d(hist_size/2);

  generate(begin(values), end(values), [&](){ return d(gen) % hist_size; });

  cout << "Size of the histogram: " << hist_size << std::endl;

  cout << "Using seq: " 
       << Histogram<unsigned>(experimental::parallel::seq, values, hist_size).count() 
       << " us" << endl;

  cout << "Using par: " 
       << Histogram<std::atomic_uint>(experimental::parallel::par, values, hist_size).count() 
       << " us" << endl;
}

int main()
{
  constexpr unsigned max_small = 5, max_large = 100;

  // high collision
  test(max_small);

  // low collision
  test(max_large);
}

