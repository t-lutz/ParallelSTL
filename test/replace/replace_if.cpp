#include <parallel>
#include <array>
#include <iostream>
#include <functional>

int main()
{
    std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    // replace all the elements < 5 by 55
    std::replace_if(std::execution_policy::par, 
                    s.begin(), s.end(),
                    [](const int &i){ return i < 5;}, 55);

    for (int a : s)
        std::cout << a << " ";
    std::cout << '\n';
}
