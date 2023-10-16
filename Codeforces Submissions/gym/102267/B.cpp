#include <iostream>
#include <vector>
using integer=std::int64_t;
class factoriser
{
    std::vector<bool> is_prime;
public:
    factoriser(int L):is_prime(L+1,true){
        for(integer i=2;i<=L;i++) if(is_prime[i]) for(integer j=i*i;j<=L;j+=i)
            is_prime[j]=false;
        is_prime[0]=false;
        is_prime[1]=false;
    }
    bool prime(int k)
    {
        return is_prime[k];
    }
};
constexpr int L=1e7;
int main()
{
    factoriser F(L);
    int n;
    std::cin >> n;
    for(int i=0;i<=n;i++)
    {
        if(F.prime(i) && F.prime(n-i))
        {
            std::cout << i << ' ' << n-i << '\n';
            return false;
        }
    }
    std::cout << -1 << '\n';
    return false;
}