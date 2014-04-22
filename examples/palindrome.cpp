#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include <experimental/algorithm>

// This should be converted to a dynamic policy when they are implemented
template<typename T>
auto palindrome(T && policy, const std::string & str)
  -> std::chrono::microseconds
{
  using namespace std;
  using namespace std::experimental;

  auto start = chrono::high_resolution_clock::now();
  const auto pal = equal(policy, begin(str), begin(str) + str.length()/2, str.rbegin());
  auto finish = chrono::high_resolution_clock::now();

  cout << "The string is" << (pal ? "" : " not") << " a palindrome." << endl;

  return chrono::duration_cast<chrono::microseconds>(finish-start); 
}

int main()
{
  using namespace std;

  vector<double> values(5000000);
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> d(1, 2);

  // a six is a six is a six is a..
  string str = "asixis";
  for(unsigned i = 0; i < 22; ++i)
    str += str;
  str += "a";

  cout << "Testing string of " << str.length() << " characters." << endl;

  cout << "Using seq: " << endl; 
  auto time_seq = palindrome(experimental::parallel::seq, str);
  cout << "seq took " << time_seq.count() << " us" << endl;

  // std::equal is not yet implemented for par
#if 0
  cout << "Using par: " << endl; 
  auto time_par = palindrome(experimental::parallel::par, str);
  cout << "par took " << time_par.count() << " us" << endl;
#endif
}


