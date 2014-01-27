#include <parallel>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v1(10);

    std::fill(std::execution_policy::par, v1.begin(), v1.end(), -1);

    for (auto elem : v1)
        std::cout << elem << " ";
    std::cout << "\n";
}
