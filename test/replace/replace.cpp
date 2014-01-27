#include <parallel>
#include <array>
#include <iostream>
#include <functional>

int main()
{
    std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    // replace all 8s by 88
    std::replace(std::execution_policy::par, s.begin(), s.end(), 8, 88);

    for (int a : s)
        std::cout << a << " ";
    std::cout << '\n';
}
