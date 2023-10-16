#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

constexpr int M=3;

int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        std::string S;
        for(int i=0;i<M;i++)
        {
            std::cin >> S;
            for(int j=0;j<M*n;j++) if(S[j]=='*')
                A[j/3]++;
        }
        std::cout << (*std::max_element(A.begin(),A.end())<<2) << '\n';
    }
}