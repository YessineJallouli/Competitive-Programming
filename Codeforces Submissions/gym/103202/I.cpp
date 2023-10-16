#include <iostream>
#include <numeric>
#include <cmath>
using natural=std::int64_t;
int main() {
    natural M,H,A;
    std::cin >> H >> M >> A;
    natural d=std::gcd<natural>(H-1,M);
    std::cout << std::min((2*(A/d)+1)*d,M*H);
    return 0;
}