#include <iostream>
#include <vector>
#include <cmath>

using integer = std::int64_t;

class factoriser
{
    int L;
    std::vector<integer> d;
    std::vector<integer> P;
public:
    factoriser(integer _L):L(_L),d(L+1)
    {
        for(integer i=2;i<=L;i++) if(!d[i])
        {
            d[i]=i;
            P.push_back(i);
            for(integer j=i*i;j<=L;j+=i) if(!d[j])
                d[j]=i;
        }
    }

    auto smallest_divisor(integer m)
    {
        if(m<=L)
            return d[m];
        else
        {
            auto R=std::sqrt(m);
            for(auto p:P)
            {
                if(p>R)
                    break;
                else if(m%p==0)
                    return p;
            }
            return m;
        }
    }
};
constexpr integer L=1e6;

int main()
{
    factoriser F(L);
    int T;
    std::cin >> T;
    while(T--)
    {
        integer n;
        std::cin >> n;
        auto p=F.smallest_divisor(n);
        auto q=n/p;
        integer s=1;
        std::cout << q*s << ' ' << (p-s)*q << '\n';
    }
}