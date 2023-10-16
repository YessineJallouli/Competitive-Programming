#include <iostream>
#include <array>
#include <algorithm>

constexpr int M=7;
constexpr int S=5;


int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        std::string I;
        std::cin >> I;
        std::array<int,M> B{};
        for(int i=0;i<M;i++)
            B[i]=I[i]-'A'+1;
        bool possible=false;
        for(int a=0;a<M;a++) for(int b=a;b<M;b++) for(int c=a+1;c<M;c++) for(int d=c;d<M;d++) if(c!=a && c!=b && d!=a && d!=b)
        {
            std::array<int,2*S+1> A{};
            for(int s=0;s<M;s++) if(s!=a && s!=b && s!=c && s!=d)
                    A[B[s]]++;
            if(a!=b)
                A[B[a]+B[b]]++;
            else
                A[B[a]]++;

            if(c!=d)
                A[B[c]+B[d]]++;
            else
                A[B[c]]++;
            possible=*std::min_element(A.begin()+1,A.begin()+S+1)>0;
            if(possible)
                goto end;
        }
        end:
        std::cout << (possible?"YES":"NO") << '\n';
    }
}