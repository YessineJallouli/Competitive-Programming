#include <iostream>
#include <complex>

using real=long double;
using integer=std::int64_t;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    int C=0;
    while(T--)
    {
        C++;
        integer n,m;
        std::cin >> n >> m;
        integer a=std::ceil((-1+std::sqrt(1+8.L*m))/2.L)-1;
        integer b=m-a*(a+1)/2-1;
        std::cout << "Case " << C << ": " << a << ' ' << b << '\n';
    }
}