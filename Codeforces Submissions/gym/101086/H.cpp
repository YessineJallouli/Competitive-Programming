#include <iostream>
int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        int a,b;
        std::cin >> a >> b;
        std::cout << std::max(a*a,b*b) << '\n';
    }
}