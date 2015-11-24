#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include <experimental/algorithm>

template<typename T, class UnaryPredicate, typename U>
auto myfind(T && policy, const std::vector<U> & values, UnaryPredicate pred)
  -> std::chrono::microseconds
{
	using namespace std;
	using namespace std::experimental; 
	
	auto start = chrono::high_resolution_clock::now();
	auto result = find_if(policy, begin(values), end(values), pred);
	auto finish = chrono::high_resolution_clock::now();
	
	if (result != end(values)){	
		cout << "Value found: " << *result << " at position: "
		     << &(*result) - &(*begin(values)) << endl;
	} else {
		cout << "No such value found" << endl;
	}
	
	return chrono::duration_cast<chrono::microseconds>(finish-start); 
}

int main()
{
	using namespace std;
	
	vector<int> values(5000000);
	for (size_t i = 0; i < values.size(); i++){
		values[i] = (int)i;
	}
	
	auto pred = [](int a){
		return false;
		//return ((a+1)%43 == 0);
	};
	
	cout << "Using seq:   " 
	     << myfind(experimental::parallel::seq, values, pred).count() 
	     << " us" << endl;
	
	cout << "Using par:   " 
	     << myfind(experimental::parallel::par, values, pred).count() 
	     << " us" << endl;
}
