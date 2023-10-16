#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ask(ll x) {
    cout << "? " << x << endl;
    int n; cin >> n;
    return n;
}

using integer =std::int64_t;
std::set<integer> divisors(integer n)
{
    std::set<integer> D;
    for(integer i=1;i<=std::sqrt(n);i++)
        if(n%i==0)
        {
            D.emplace(i);
            D.emplace(n/i);
        }
    return D;
}


constexpr integer L=1e13;
constexpr integer I=41;
int main()
{
    random_device dev;
    mt19937_64 g(dev());
    uniform_int_distribution<integer> X(0,L);
    std::set<integer> S;
    while(S.size()<I)
        S.emplace(X(g));
    std::vector<std::pair<integer,integer>> Q;
    for(auto s:S) {
        std::cout << "? " << s << std::endl;
        integer R;
        std::cin >> R;
        Q.emplace_back(s,R);
    }
    std::set<integer> potential;
    for(auto [a,x]:Q)
    {
        if(potential.empty())
            potential= divisors(a-x);
        else
        {
            auto D1= divisors(a-x);
            std::set<integer> D2;
            for(auto p:potential)
                if(D1.contains(p) && p > x)
                    D2.emplace(p);
            potential=std::move(D2);
        }
    }
    std::cout << "! " << *potential.begin() << std::endl;
}