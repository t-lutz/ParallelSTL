#include <parallel>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v1(10);

    // fill first half with -1
    auto cursor = std::fill_n(std::execution_policy::par, v1.begin(), 5, -1);

    // fill second half with 10
    std::fill_n(std::execution_policy::par, cursor, 5, 10);

    for (auto elem : v1)
        std::cout << elem << " ";
    std::cout << "\n";
}
