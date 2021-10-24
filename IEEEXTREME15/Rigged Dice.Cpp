#include <iostream>
#include <vector>
#include <utility>

using natural = std::int16_t;
using couple=std::pair<natural,natural>;
using real = float;
int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        int n;
        std::cin >> n;
        natural S[2]{0,0};
        natural C[2][6]{{0,0,0,0,0,0},{0,0,0,0,0,0}};
        std::vector<natural> A(n),B(n);
        natural R=0;
        for(int i=0;i<n;i++)
            std::cin >> A[i] >> B[i];
        for(int i=0;i<n;i++)
        {
            C[R][A[i]-1]++;
            C[1-R][B[i]-1]++;
            S[0]+=A[i];
            S[1]+=B[i];
            if(S[0]!=S[1])
                R=1-R;
        }
        std::cout << 1+(C[0][5]<C[1][5]) << '\n';
    }
    return 0;
}
