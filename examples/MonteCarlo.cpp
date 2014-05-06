#include <vector>
#include <random>
#include <limits>
#include <iostream>
#include <chrono>
#include <experimental/algorithm>
#include <experimental/numeric>
using namespace std;

double test_pi() {
  thread_local static random_device rd;

  constexpr unsigned samples = 10000;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> dis(0,1);
  
  unsigned sum = 0;
  for(unsigned i = 0; i < samples; ++i){
    const double x = dis(gen), y = dis(gen);
    double dist = sqrtf(x*x + y*y);
    if(dist <= 1.0f) 
      sum++;
  }
  
  sum *= 4;
  return static_cast<double>(sum)/static_cast<double>(samples);
}

template<typename T>
auto extimate_pi(T && policy)
  -> std::chrono::microseconds
{
  using namespace std::experimental;
  constexpr unsigned samples = 10000;
  vector<double> estimates(samples);

  auto start = chrono::high_resolution_clock::now();
  
  parallel::generate(policy, begin(estimates), end(estimates), test_pi);
  auto pi = parallel::reduce(policy, begin(estimates), end(estimates)) / double{samples};

  auto finish = chrono::high_resolution_clock::now();

  cout << "pi = " << pi << endl; 

  return chrono::duration_cast<chrono::microseconds>(finish-start); 
}

int main(){
  using namespace std::experimental;
  cout << "Using seq: " << endl; 
  auto time_seq = extimate_pi(parallel::seq);
  cout << "seq took " << time_seq.count() << " us" << endl;

  cout << "Using par: " << endl; 
  auto time_par = extimate_pi(parallel::par);
  cout << "seq took " << time_par.count() << " us" << endl;
}
