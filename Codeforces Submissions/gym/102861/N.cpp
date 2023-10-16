//
// Created by ramizouari on 14/10/2021.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <cmath>
#include <algorithm>
using integer=std::int64_t;
class factoriser
{
    integer reduce_over_divisors(int n,const std::function<integer(integer)> &f,const std::function<integer(integer,integer)>&O,
                                 int o,const std::vector<integer> &P);
public:
    virtual integer smallest_divisor(integer n) = 0;
    virtual bool is_prime(integer n);
    virtual std::vector<integer> prime_factors(integer n);
    virtual std::unordered_map<integer,integer> factorise(integer n);
    integer sum_over_divisors(int n,const std::function<integer(integer)> &f);
    integer multiply_over_divisors(int n,const std::function<integer(integer)> &f);
    integer reduce_over_divisors(int n,const std::function<integer(integer)> &f,const std::function<integer(integer,integer)> &O);
};

class naive_factoriser:public factoriser
{
    integer smallest_divisor(integer n) override;
};

class simple_sieve:public factoriser
{
    integer N;
    std::vector<integer> p_list,smallest_d;
public:
    explicit simple_sieve(integer _N);
    integer smallest_divisor(integer n) override;
};

class eratosthenes_sieve:public factoriser
{
    integer N;
    std::vector<integer> p_list,smallest_d;
public:
    eratosthenes_sieve(integer _N);
    integer smallest_divisor(integer n) override;
    std::vector<integer>& prime_list()
    {
        return p_list;
    }

};

std::vector<integer> factoriser::prime_factors(integer n)
{
    if(n==1)
        return {};
    auto s = smallest_divisor(n);
    auto P=prime_factors(n/s);
    if(P.empty() || P.back()>s)
        P.push_back(s);
    return P;
}

std::unordered_map<integer, integer> factoriser::factorise(integer n)
{
    std::unordered_map<integer,integer> mapper;
    while(n>1)
    {
        auto s= smallest_divisor(n);
        mapper[s]++;
        n/=s;
    }
    return mapper;
}

bool factoriser::is_prime(integer n) {
    return smallest_divisor(n)==n;
}

integer factoriser::sum_over_divisors(int n, const std::function<integer(integer)> &f)
{
    return reduce_over_divisors(n,f,std::plus<integer>());
}

integer factoriser::reduce_over_divisors(int n, const std::function<integer(integer)> &f,const std::function<integer(integer,integer)>&O, int o,
                                         const std::vector<integer> &P)
{
    integer R=f(n);
    int m=P.size();
    for(int i=o;i<m;i++) if(n%P[i]==0)
            R+= reduce_over_divisors(n/P[i],f,O,i,P);
    return R;
}
integer factoriser::reduce_over_divisors(int n,const std::function<integer(integer)> &f,const std::function<integer(integer,integer)> &O)
{
    auto P= prime_factors(n);
    return reduce_over_divisors(n,f,O,0,P);
}

integer factoriser::multiply_over_divisors(int n, const std::function<integer(integer)> & f) {
    return reduce_over_divisors(n,f,std::multiplies<integer>());
}

integer naive_factoriser::smallest_divisor(integer n)
{
    auto L=sqrtl(n);
    for(int i=2;i<=L;i++) if(n%i==0)
            return i;
    return n;
}

simple_sieve::simple_sieve(integer _N) :N(_N),smallest_d(N+1,0)
{
    for(int i=2;i<=N;i++)
    {
        integer L=sqrt(i);
        for(auto p:p_list)
        {
            if(i%p==0)
            {
                smallest_d[i]=p;
                break;
            }
            if (p > L)
                break;
        }
        if(smallest_d[i]==0) {
            smallest_d[i] = i;
            p_list.push_back(i);
        }
    }
}

integer simple_sieve::smallest_divisor(integer n) {
    return smallest_d[n];
}

eratosthenes_sieve::eratosthenes_sieve(integer _N) :N(_N),smallest_d(N+1)
{
    std::vector<bool> is_prime(N+1,true);
    for(integer i=2;i<=N;i++) if(is_prime[i])
        {
            smallest_d[i]=i;
            p_list.push_back(i);
            for(integer j=i;i*j<=N;j++)
            {
                is_prime[i*j]=false;
                smallest_d[i*j]=i;
            }
        }
}

integer eratosthenes_sieve::smallest_divisor(integer n) {
    return smallest_d[n];
}

using natural=std::int64_t;

template<typename A>
A pow(const A& u, long long n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return u;
    A r = pow(u, n / 2);
    r *= r;
    return r * pow(u, n % 2);
}

class bipartite_graph
{
    int n,m;
    std::vector<std::map<int,int>> A,B;
    std::vector<natural> C,P,&P_list;
public:
    bipartite_graph(int _n,int _m,std::vector<natural>&_P_list):n(_n),m(_m),A(m),B(n),C(n),P(m),P_list(_P_list)
    {

    }
    void set(int b,natural c)
    {
        C[b]=c;
    }
    void connect(int a,int b,int d)
    {
        A[a][b]=d;
        B[b][a]=d;
    }

    void disconnect(int a,int b)
    {
        A[a].erase(b);
        B[b].erase(a);
    }

    void find(int t)
    {
        auto s=std::distance(P_list.begin(),std::upper_bound(P_list.begin(),P_list.end(),t==0?0:P[t-1]));
        auto size=P_list.size();
        auto q=A[t].begin()->first;
        for(auto i=s;i<size;i++) if(C[q]%P_list[i]==0)
        {
            P[t]=P_list[i];
            return;
        }
        natural R=C[q];
        for(auto [h,d]:B[q])
            if(h!=t)
                R/=pow(P[h],d);
        P[t]=R;
    }

    void guess_all()
    {
        for(int i=0;i<m;i++)
            find(i);
    }

    const std::vector<natural>& get_primes() const
    {
        return P;
    }
};

const natural L=sqrtl(1.01e15);
int main()
{
    int m,n,k;
    std::ios_base::sync_with_stdio(false);
    std::cin >> m >> n >> k;
    eratosthenes_sieve S(L);
    bipartite_graph BG(n,m,S.prime_list());
    for(int i=0;i<n;i++)
    {
        natural c;
        std::cin >> c;
        BG.set(i,c);
    }
    for(int i=0;i<k;i++)
    {
        natural a,b,d;
        std::cin >> a >> b >> d;
        BG.connect(a-1,b-1,d);
    }
    BG.guess_all();
    for(auto s:BG.get_primes())
        std::cout << s << ' ';
}