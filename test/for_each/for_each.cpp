#include <vector>
#include <parallel>
#include <iostream>

int main(){
  std::vector<int> test{1,2,3,4,5,6,7,8,9,10,11,12};
  
  std::cout << "before: ";
  for(auto i : test)
    std::cout << i << " ";
  std::cout << std::endl;

  std::for_each(std::execution_policy::par,        // policy
                std::begin(test), std::end(test),  // range
                [](int &i){i *= 2;});              // functor

  std::cout << "after: ";
  for(auto i : test)
    std::cerr << i << " ";
  std::cout << std::endl;
}
