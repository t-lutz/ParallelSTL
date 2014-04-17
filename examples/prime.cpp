#include <chrono>
#include <vector>
#include <random>
#include <iostream>
#include <experimental/algorithm>

// Type of the generated ints. std::uint64_t can take a while.
typedef std::uint32_t number_t;

/**
 * Test if a number os a prime.
 */
static bool isPrime(const number_t & n)
{
  if (n < 4) return n > 1;
  if (n % 2 == 0) return false;
  const auto sq = (int)sqrt(n) + 1;
  for (number_t i = 3; i <= sq; i += 2)
    if (n % i == 0) return false;
  return true;
}

/**
 * Finding the first prime. The parallel version will have a big disadvantage if
 * it is scanning the entire array since the sequential version will stop at the first
 * match.
 */
template<typename t>
auto find_prime(t && policy, const std::vector<number_t> & numbers)
  -> std::chrono::microseconds
{
  using namespace std;
  auto start = chrono::high_resolution_clock::now();
  auto it = find_if(policy, begin(numbers), end(numbers), isPrime);
  auto finish = chrono::high_resolution_clock::now();
    
  cout << "contains at least one prime: " << boolalpha << (it != end(numbers)) << endl;
  if(it != end(numbers))
    cout << "at position: " << distance(begin(numbers), it) << endl;
 
  return chrono::duration_cast<chrono::microseconds>(finish-start); 
}

template<typename t>
auto count_prime(t && policy, const std::vector<number_t> & numbers)
  -> std::chrono::microseconds
{
  using namespace std;
  auto start = chrono::high_resolution_clock::now();
  auto count = count_if(policy, begin(numbers), end(numbers), isPrime);
  auto finish = chrono::high_resolution_clock::now();
    
  cout << "Number of prime numbers: " << count << endl;
 
  return chrono::duration_cast<chrono::microseconds>(finish-start); 
}


int main(){
  using namespace std;
  default_random_engine gen(6);
  uniform_int_distribution<number_t> d(numeric_limits<number_t>::max()/2,
                                       numeric_limits<number_t>::max());

  vector<number_t> numbers(100000);
  generate(begin(numbers), end(numbers), [&](){ return d(gen); });

  { // test std::find_if
    cout << endl << "Testing std::find_if" << endl;    

    cout << "Using seq: " << endl; 
    auto time_seq = find_prime(experimental::parallel::seq, numbers);
    cout << "seq took " << time_seq.count() << " us" << endl;

    cout << "Using par: " << endl; 
    auto time_par = find_prime(experimental::parallel::par, numbers);
    cout << "par took " << time_par.count() << " us" << endl;
  }

  { // test std::count_if
    cout << endl << "Testing std::count_if" << endl;    

    cout << "Using seq: " << endl; 
    auto time_seq = count_prime(experimental::parallel::seq, numbers);
    cout << "seq took " << time_seq.count() << " us" << endl;

    cout << "Using par: " << endl; 
    auto time_par = count_prime(experimental::parallel::par, numbers);
    cout << "par took " << time_par.count() << " us" << endl;
  }

  { // test std::replace_if
    cout << endl << "Testing std::replace_if" << endl;

    auto copy = numbers;
    cout << "Using seq: " << endl; 
    auto start = chrono::high_resolution_clock::now(); 
    replace_if(experimental::parallel::seq, begin(copy), end(copy), isPrime, 0);
    auto finish = chrono::high_resolution_clock::now();
    cout << "seq took " << chrono::duration_cast<chrono::microseconds>(finish-start).count() << " us" << endl;

    copy = numbers;
    cout << "Using par: " << endl;
    start = chrono::high_resolution_clock::now(); 
    replace_if(experimental::parallel::par, begin(copy), end(copy), isPrime, 0);
    finish = chrono::high_resolution_clock::now();
    cout << "seq par " << chrono::duration_cast<chrono::microseconds>(finish-start).count() << " us" << endl;
  }
}

