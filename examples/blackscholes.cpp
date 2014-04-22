// adapted from http://www.espenhaug.com/black_scholes.html
#include <cmath>
#include <vector>
#include <iostream>
#include <chrono>
#include <experimental/algorithm>

constexpr double PI  =3.141592653589793238463;

// The cumulative normal distribution function 
double CND( double X )
{
  double L, K, w ;

  double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
  double const a4 = -1.821255978, a5 = 1.330274429;

  L = fabs(X);
  K = 1.0 / (1.0 + 0.2316419 * L);
  w = 1.0 - 1.0 / sqrt(2 * PI) * exp(-L *L / 2) * (a1 * K + a2 * K *K + a3 * pow(K,3) + a4 * pow(K,4) + a5 * pow(K,5));

  if (X < 0 ){
    w= 1.0 - w;
  }
  return w;
}

struct Option {
  // members to compute
  double call, put;
  // compute parameters
  double S, X, T, r, v;
};

// This should be converted to a dynamic policy when they are implemented
template<typename T>
auto BlackScholes(T && policy, const std::vector<Option> & options)
  -> std::chrono::microseconds
{
  using namespace std;
  using namespace std::experimental;
  auto copy = options;
  auto start = chrono::high_resolution_clock::now();
  for_each(policy, begin(copy), end(copy), 
      [](Option & opt) {
        const double d1 = (std::log(opt.S/opt.X)+(opt.r+opt.v*opt.v/2)*opt.T)/(opt.v*std::sqrt(opt.T));
        const double d2 = d1-opt.v*sqrt(opt.T);

        opt.call = opt.S *CND(d1)-opt.X * exp(-opt.r*opt.T)*CND(d2);
        opt.put = opt.X * exp(-opt.r * opt.T) * CND(-d2) - opt.S * CND(-d1);
      });
  auto finish = chrono::high_resolution_clock::now();

  // make sure the compiler is not too clever when optimizing the loop
  for(auto & opt : copy) if(opt.call == 0.01 && opt.put == PI) std::cout << ".";

  return chrono::duration_cast<chrono::microseconds>(finish-start); 
}


int main()
{
  using namespace std;
  // compute 5M options
  vector<Option> options(5000000);

  cout << "Using seq: " 
       << BlackScholes(experimental::parallel::seq, options).count() 
       << " us" << endl;

  cout << "Using par: " 
       << BlackScholes(experimental::parallel::par, options).count() 
       << " us" << endl;
}

