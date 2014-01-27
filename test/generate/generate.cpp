#include <vector>
#include <parallel>
#include <iostream>
#include <cstdlib>

int main(){
  std::vector<int> v(5);
  std::generate(std::execution_policy::par, v.begin(), v.end(), std::rand);

  std::cout << "v: ";
  for (auto i: v)
     std::cout << i << " ";
  std::cout << "\n";
}
