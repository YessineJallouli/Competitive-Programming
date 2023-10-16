#include <iostream>
#include <numbers>
#include <numeric>
#include <cmath>
using real=long double;

int main()
{
    int n,L;
    std::cin >> n >> L;
    auto R=L/(2*std::sin(std::numbers::pi/n));
    std::cout.precision(8);
    std::cout << std::fixed << R*R*std::numbers::pi << '\n';
}