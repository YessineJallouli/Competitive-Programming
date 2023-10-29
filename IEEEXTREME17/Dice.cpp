//30%
#include <iostream>
#include <unordered_map>
#include <map>
//
// Created by ASUS on 30/11/2021.
//
#ifndef __MODULAR__ARITHMETIC__
#define __MODULAR__ARITHMETIC__
#include <cstdint>
#include <utility>
//
// Created by ramizouari on 01/12/2021.
//

#ifndef ACPC_PREPARATION_ABSTRACT_ALGEBRA_H
#define ACPC_PREPARATION_ABSTRACT_ALGEBRA_H
#include <complex>
#include <functional>
using natural = std::uint64_t;
using integer = std::int64_t;
using real = long double;
using IR=real;
using IC= std::complex<IR>;
constexpr real epsilon=1e-7;

template<typename R>
R commutator(R a,R b)
{
    return a*b-b*a;
}

template<typename M,typename G=typename M::base_field>
M conj(M a)
{
    if constexpr (std::is_same_v<G, IC>)
    {
        if constexpr (std::is_same_v<G, M>)
            return std::conj(a);
        else for (auto& s : a)
            s = conj<typename std::remove_reference<decltype(s)>::type, G>(s);
    }
    return a;
}

template<typename R,typename ...StructureMetaData>
R pow(R a, long long n,StructureMetaData ... meta_info)
{
    if(n==0)
        return R(1,meta_info...);
    else if(n==1)
        return a;
    auto s=pow(a,n/2);
    return n%2?s*s*a:s*s;
}

template<typename R>
bool is_zero(const R&a)
{
    return a==R{};
}

inline bool is_zero(const IC&a)
{
    return std::abs(a) < epsilon;
}

inline bool is_zero(const real &a)
{
    return std::abs(a) < epsilon;
}

template<typename R>
R gcd(R a,R b)
{
    if(a<b)
        std::swap(a,b);
    R q,tmp;
    while(!is_zero(b))
    {
        q=a/b;
        tmp=b;
        b=a-b*q;
        a=tmp;
    }
    return a;
}

template<typename R>
R lcm(const R &a,const R &b)
{
    return a*b/gcd(a,b);
}

template<typename R=integer>
struct egcd_t
{
    R a,b,d;
};

template<typename R>
egcd_t<R> egcd(R a,R b)
{
    if(a<b)
    {
        auto e = egcd(b, a);
        std::swap(e.a,e.b);
        return e;
    }
    R q,s1=1,s2=0,t1=0,t2=1,tmp;
    while(!is_zero(b))
    {
        q=a/b;
        tmp=s2;
        s2=s1-q*s2;
        s1=tmp;
        tmp=t2;
        t2=t1-q*t2;
        t1=tmp;
        tmp=b;
        b=a-b*q;
        a=tmp;
    }
    return {s1,t1,a};
}

template<typename R>
std::pair<R,R> bezout(R a, R b)
{
    auto [u,v,_]=egcd(a,b);
    return {u,v};
}

template<typename B>
B next_gray(B n)
{
    return n^(n>>1);
}

template<typename F,typename R>
std::pair<integer,integer> floyd_functional_cycle(F && f,R x0)
{
    /*
     * Find a period
     * */
    R x=x0,y=x;
    integer m=0;
    do
    {
        x=f(x);
        y=f(f(y));
        m++;
    }while(y!=x);
    /*
     * Find offset
     * */
    x=x0,y=x;
    for(int i=0;i<m;i++)
        y=f(y);
    int offset=0;
    while(x!=y)
    {
        x=f(x);
        y=f(y);
        offset++;
    }

    /*
     * Find fundamental period
     * */
    y=f(x);
    integer period=1;
    while(x!=y) {
        y = f(y);
        period++;
    }
    return std::make_pair(period,offset);
}


template<typename F,typename R>
integer functional_period(F &&f, R x)
{
    /*
    * Find a period
    * */
    R y=x;
    integer m=0;
    do
    {
        x=f(x);
        y=f(f(y));
        m++;
    }while(y!=x);
    return m;
}


#endif //ACPC_PREPARATION_ABSTRACT_ALGEBRA_H
#include <random>
#include <unordered_map>
//
// Created by ASUS on 01/12/2021.
//


template<integer mod>
class cyclic
{
    integer n;
public:
    inline static bool assume_prime=true;
    inline static constexpr integer m = mod;
    cyclic(integer o=0):n((o+m)%m){}
    bool operator==(int O) const
    {
        return n==(m+O)%m;
    }

    bool operator!=(int O) const
    {
        return n!=(m+O)%m;
    }

    bool operator==(cyclic O) const
    {
        return n==O.n;
    }

    bool operator!=(cyclic O) const
    {
        return n!=O.n;
    }

    cyclic operator-() const
    {
        return cyclic(-n);
    }

    auto& operator+=(const cyclic &O)
    {
        n=(n+O.n)%m;
        return *this;
    }
    auto& operator-=(const cyclic &O)
    {
        n=(n+m-O.n)%m;
        return *this;
    }

    auto& operator*=(const cyclic &O)
    {
        n=(n*O.n)%m;
        return *this;
    }

    auto& operator/=(const cyclic &O)
    {
        return (*this)*=O.inv();
    }

    auto operator*(const cyclic &O) const
    {
        auto w=*this;
        return w*=O;
    }

    auto operator+(const cyclic &O) const
    {
        auto w=*this;
        return w+=O;
    }

    auto operator-(const cyclic &O) const
    {
        auto w=*this;
        return w-=O;
    }

    auto operator/(const cyclic &O) const
    {
        return (*this)*O.inv();
    }

    cyclic pinv() const
    {
        return egcd(n,m).a;
    }

    auto inv() const
    {
        if(assume_prime)
            return pow(*this,m-2);
        else return pinv();
    }

    auto& operator++()
    {
        return *this+=1;
    }

    auto& operator--()
    {
        return *this-=1;
    }

    auto operator++(int)
    {
        cyclic r(n);
        *this += 1;
        return r;
    }

    auto operator--(int)
    {
        cyclic r(n);
        *this -= 1;
        return r;
    }

    explicit operator integer&()
    {
        return n;
    }

    explicit operator const integer&() const
    {
        return n;
    }
};

template<integer m>
auto operator*(int k,cyclic<m> s)
{
    return s*k;
}

template<integer m>
auto operator+(int k,cyclic<m> s)
{
    return s+k;
}

class d_cyclic
{
    integer n;
public:
    inline static integer m=1;
    inline static bool assume_prime=true;
    d_cyclic(integer o=0):n((o+m)%m){}
    bool operator==(int O) const
    {
        return n==(m+O)%m;
    }

    bool operator!=(int O) const
    {
        return n!=(m+O)%m;
    }

    bool operator==(d_cyclic O) const
    {
        return n==O.n;
    }

    bool operator!=(d_cyclic O) const
    {
        return n!=O.n;
    }

    auto& operator+=(const d_cyclic &O)
    {
        n=(n+O.n)%m;
        return *this;
    }
    auto& operator-=(const d_cyclic &O)
    {
        n=(n+m-O.n)%m;
        return *this;
    }

    auto& operator*=(const d_cyclic &O)
    {
        n=(n*O.n)%m;
        return *this;
    }

    auto inv() const
    {
        if(assume_prime)
            return pow(*this,m-2);
        else return pinv();
    }

    auto& operator/=(const d_cyclic &O)
    {
        return (*this)*=O.inv();
    }

    auto operator*(const d_cyclic &O) const
    {
        auto w=*this;
        return w*=O;
    }

    auto operator+(const d_cyclic &O) const
    {
        auto w=*this;
        return w+=O;
    }

    d_cyclic operator-() const
    {
        return d_cyclic(m-n);
    }

    auto operator-(const d_cyclic &O) const
    {
        auto w=*this;
        return w-=O;
    }

    auto operator/(const d_cyclic &O) const
    {
        return (*this)*O.inv();
    }

    d_cyclic pinv() const
    {
        return egcd(n,m).a;
    }

    auto& operator++()
    {
        return *this+=1;
    }

    auto& operator--()
    {
        return *this-=1;
    }

    auto operator++(int)
    {
        d_cyclic r(n);
        *this += 1;
        return r;
    }

    auto operator--(int)
    {
        d_cyclic r(n);
        *this -= 1;
        return r;
    }

    explicit operator integer&()
    {
        return n;
    }

    explicit operator const integer&() const
    {
        return n;
    }
};

inline auto operator*(int k,d_cyclic O)
{
    return O*=k;
}

template<>
struct std::hash<d_cyclic>
{
    inline static std::random_device dev=std::random_device();
    inline static std::mt19937_64 g=std::mt19937_64(dev());
    inline static constexpr integer M=1e9+7;
    std::uniform_int_distribution<integer> d=std::uniform_int_distribution<integer>(1,M);
    integer a=d(g),b=d(g);
public:
    auto operator()(const d_cyclic &x) const
    {
        return (a*static_cast<integer>(x)+b)%M;
    }
};

template<integer m>
struct std::hash<cyclic<m>>
{
    inline static std::random_device dev=std::random_device();
    inline static std::mt19937 g=std::mt19937(dev());
    inline static constexpr integer M=1e9+7;
    std::uniform_int_distribution<integer> d=std::uniform_int_distribution<integer>(1,M);
    integer a=d(g),b=d(g);
public:
    size_t operator()(const cyclic<m> &x) const noexcept
    {
        return (a*static_cast<integer>(x)+b)%M;
    }
};

template<typename cyclic_ring>
integer discrete_log(cyclic_ring a, cyclic_ring r)
{
    integer s=std::ceil(std::sqrt(cyclic_ring::m));
    cyclic_ring u=pow(a,s),w=1;
    std::unordered_map<cyclic_ring,integer> mapper;
    for(integer i=0;i<=s;i++,w*=a)
        mapper[r*w]=i;
    w=u;
    for(integer i=1;i<=s;i++,w*=u)
        if(mapper.count(w))
            return i*s-mapper[w];
    return -1;
}

inline std::vector<integer> inverse_table(int n,int prime)
{
    std::vector<integer> I(n + 1);
    I[0] = I[1] = 1;
    for (int i = 2; i <= n; i++)
        I[i] = I[prime % i] *
                (prime - prime / i) % prime;
    return I;
}

#endif
constexpr integer M=998244353;
using IK=cyclic<M>;
class Phi
{
    IK inv_6=IK{6}.inv();
    std::map<std::pair<int,int>,IK> mapper;
public:
    IK evaluate(int n, int m)
    {
        if(n<m)
            return 0;
        if(mapper.count({n,m}))
            return mapper[{n,m}];
        if(m==0)
            return n==0;
        IK R;
        for(int i=1;i<=6;i++)
            R+=inv_6* evaluate(n-i,m-1);
        return mapper[{n,m}]=R;
    }
    auto operator()(int n,int m)
    {
        return evaluate(n,m);
    }
};

class Rho
{
    std::map<std::pair<int,int>,IK> mapper;
    IK inv_6=IK{6}.inv();
    Phi & phi;
public:
    Rho(Phi &phi):phi(phi)
    {

    }
    IK evaluate(int n,int k)
    {
        if(k==1)
            return (n<= 6) && (n>=1)? inv_6:0;
        if(mapper.count({n,k}))
            return mapper[{n,k}];
        return mapper[{n,k}] = ((k-1)* evaluate(n,k-1)  +phi.evaluate(n,k)) * IK{k}.inv();
    }
    auto operator()(int n,int k)
    {
        return evaluate(n,k);
    }
};

int main()
{
    integer n,k;
    Phi phi;
    Rho rho(phi);
    std::cin >> n >> k;
    std::cout << static_cast<integer>(rho(n,k));
}
