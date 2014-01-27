#include <parallel>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v1{1,2,3,4,5,6};
    std::cerr << std::reduce(std::execution_policy::par, v1.begin(), v1.end()) << std::endl;
}
