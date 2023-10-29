//65%
#include <iostream>
#include <vector>
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

#endif //ACPC_PREPARATION_ABSTRACT_ALGEBRA_H
#include <random>
#include <unordered_map>
//
// Created by ASUS on 01/12/2021.
//
#ifndef __NUMBERTHEORY_H__
#define __NUMBERTHEORY_H__
#include <cstdint>
#include <vector>
#include <map>
#include <numeric>
#include <cmath>
#include <stack>
#include <algorithm>



#endif
//
// Created by ramizouari on 01/12/2021.
//
#ifndef __RING__EXTENSION__
#define __RING__EXTENSION__
//
// Created by ramizouari on 01/12/2021.
//
#ifndef __POLYNOMIAL__H__
#define __POLYNOMIAL__H__
#include <vector>
#include <map>

/**
* @brief Polynomial class
* @details This is the class of polynomials over a commutative ring R
* @tparam R the type of the coefficients
* @Requirements
* <strong>R</strong> is a commutative ring
* @Notes
* Formally this class is simply R[x]
*/
template<typename R>
struct polynomial
{
    std::vector<R> p;

public:
    bool operator==(const R& a) const
    {
        if (is_zero(a))
            return p.empty();
        else return degree() == 0 && p.front() == a;
    }

    bool operator==(const polynomial<R> &) const = default;

    void reduce()
    {
        while(!p.empty() && is_zero(p.back()))
            p.pop_back();
    }
    polynomial(R k):p(1,k)
    {
        reduce();
    }

    polynomial(int k = 0) :p(1, k)
    {
        reduce();
    }

    polynomial(std::vector<R> _p):p(std::move(_p))
    {
        reduce();
    }

    int degree() const
    {
        return p.size()-1;
    }

    int dim() const
    {
        return p.size();
    }

    auto& operator+=(const polynomial &O)
    {
        int r=std::max(p.size(),O.p.size());
        p.resize(r);
        for(int i=0;i<O.p.size();i++)
            p[i]+=O.p[i];
        reduce();
        return *this;
    }

    auto& operator-=(const polynomial &O)
    {
        int r=std::max(p.size(),O.p.size());
        p.resize(r);
        for(int i=0;i<O.p.size();i++)
            p[i]-=O.p[i];
        reduce();
        return *this;
    }

    polynomial operator*(const polynomial &O) const
    {
        if(O.p.empty() || p.empty())
            return polynomial(0);
        int n=degree(),m=O.degree();
        polynomial q;
        q.p.resize(n+m+1);
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++)
            q.p[i+j]+=p[i]*O.p[j];
        q.reduce();
        return q;
    }

    auto& operator*=(const polynomial &O)
    {
        auto r=(*this)*O;
        p.swap(r.p);
        return *this;
    }

    auto operator+(const polynomial &O) const
    {
        auto r=*this;
        return r+=O;
    }

    auto operator-(const polynomial &O) const
    {
        auto r=*this;
        return r-=O;
    }

    auto operator-() const
    {
        auto r=*this;
        for(auto &s:r.p)
            s=-s;
        return r;
    }

    auto operator*=(R a)
    {
        if(is_zero(a))
            p.clear();
        else for(auto& s:p)
            s*=a;
        reduce();
        return *this;
    }

    bool operator!=(R a) const
    {
        return !(*this==a);
    }

    auto& operator+=(R a)
    {
        return *this+=polynomial({a});
    }

    auto& operator-=(R a)
    {
        return *this-=polynomial({a});
    }

    auto operator+(R a) const
    {
        auto q=*this;
        return q+=a;
    }

    auto operator-(R a) const
    {
        auto q=*this;
        return q-=a;
    }

    /**
    * @details creates a preorder between polynomials based on the degree
    * @Requirements:
    * None
    * @Notes
    * This function is essential for the euclidean algorithm to work
    */
    bool operator<(const polynomial &O) const
    {
        return degree() < O.degree();
    }

    /**
     * @brief Polynomial self division
    * @details Divides the polynomial by a constant and stores the result in itself
    * @Requirements
    * One of the following:
     * <ul>
    * <li> R is an integral ring [2]
    * <li> k is invertible
     * </ul>
    */

    auto& operator/=(R k)
    {
        for(auto &s:p)
            s/=k;
        return *this;
    }

    auto operator/(R k) const
    {
        auto q=*this;
        return q/=k;
    }

    /**
     * @brief Euclidean division
    * @details Applies euclidean division between two polynomials
    * @Requirements
    * One of the following
    * <ul>
    * <li> R is a field [1]
    * <li> R is an euclidean domain [2]
    * <li> R is a commutative ring, and the dominant coefficient of <strong>O</strong> is inversible
    * <ul/>
    * @Notes
    * Even that condition [1] is a special case of [2], given that some properties of euclidean division are
    * guaranteed only if <strong>R</strong> is a field, We will seperate the two cases
    */
    std::pair<polynomial,polynomial> euclidean_division(const polynomial &O) const
    {
        if(degree() < O.degree())
            return {R(0),*this};
        polynomial q,r=*this;
        int n=degree(),m=O.degree();
        q.p.resize(n-m+1);
        for(int i=n;i>=m;i--)
        {
            q.p[i-m]=r[i]/O.p[m];
            for(int j=0;j<=m;j++)
                r.p[i+j-m]-=q.p[i-m]*O.p[j];
        }
        r.reduce();
        return {q,r};
    }

    //Get the quotient of the euclidean division
    polynomial operator/(const polynomial &O) const
    {
        return euclidean_division(O).first;
    }

    //Get the remainder of the euclidean division
    polynomial operator%(const polynomial &O) const
    {
        return euclidean_division(O).second;
    }

    auto& operator/=(polynomial &O)
    {
        p.swap(((*this)/O).p);
        return *this;
    }

    auto &operator[](int k)
    {
        return p[k];
    }

    const auto& operator[](int k) const
    {
        return p[k];
    }

    polynomial derivative() const
    {
        if (p.empty())
            return {};
        polynomial D;
        D.p.resize(degree());
    }

    /**
    * @brief Polynomial Evaluation
    * @details Evaluates the polynomial at a given point
    * Evaluates the polynomial over an associative R-algebra H
    * @Requirements
    * <strong>H</strong> is an associative algebra over <strong>R</strong>
    */
    template<typename H>
    H operator()(H a) const
    {
        H r(0);
        for(int i=degree();i>=0;i--)
            r=r*a+p[i];
        return r;
    }

    auto begin()
    {
        return p.begin();
    }

    auto end()
    {
        return p.end();
    }

    auto begin() const
    {
        return p.begin();
    }

    auto end() const
    {
        return p.end();
    }

    explicit operator std::vector<R>&()
    {
        return p;
    }

    explicit operator const std::vector<R>&() const
    {
        return p;
    }
};

template<typename R>
polynomial<R> operator*(R a,const polynomial<R> &p)
{
    auto q=p;
    return q*=a;
}

/**
* @brief The functional identity polynomial
* @details This constant is the generator of all polynomials over R.
* @Notes
* Formally, it is simply the polynomial X:x->x
*/
template<typename R>
const polynomial<R> X=polynomial<R>(std::vector<R>{0,1});

template<typename R>
polynomial<R> karatsuba_multiplication(const polynomial<R> &p,const polynomial<R> &q)
{
    constexpr int L=75;
    if(std::min(p.degree(),q.degree())<=L)
        return p*q;
    polynomial<R> a1,b1,a2,b2;
    int n=p.degree(),m=q.degree(),r=std::max(n,m)+1;
    std::vector<R> &u1=static_cast<std::vector<R>&>(a1),&u2=static_cast<std::vector<R>&>(a2),
    &v1=static_cast<std::vector<R>&>(b1),&v2=static_cast<std::vector<R>&>(b2);
    u1.resize(std::min(n+1,r/2));
    u2.resize(std::min(m+1,r/2));
    v1.resize(std::max(n+1-r/2,0));
    v2.resize(std::max(m+1-r/2,0));
    for(int i=0;i<u1.size();i++)
        u1[i]=p[i];
    for(int i=0;i<u2.size();i++)
        u2[i]=q[i];
    for(int i=0;i<v1.size();i++)
        v1[i]=p[i+r/2];
    for(int i=0;i<v2.size();i++)
        v2[i]=q[i+r/2];
    polynomial<R> r1= karatsuba_multiplication(a1,a2),
        r3= karatsuba_multiplication(b1,b2),
        t=karatsuba_multiplication(a1+b1,a2+b2),
        r2=t-r1-r3;
    polynomial<R> h;
    int s=r-r%2;
    auto &c=static_cast<std::vector<R>&>(h);
    c.resize(n+m+1);
    for(int i=0;i<=r1.degree();i++)
        c[i]+=r1[i];
    for(int i=0;i<=r2.degree();i++)
        c[i+r/2]+=r2[i];
    for(int i=0;i<=r3.degree();i++)
        c[i+s]+=r3[i];
    return h;
}
#endif
/*
 * This header contains a list of usual ring extensions:
 * 1. field of fractions for an integral ring R
 * 2. nilpotent extension of a ring R: formally it is isomorphic to R[x]/x^k where k is the nilpotence index
 * 3. idempotent extention of a ring R: formally it is isomorphic to R[x]/(x^k-x^(k-1)) where k is the idempotence index
 * 4. ring extension of a ring R with a polynomial q: formally it is isomorphic to R[x]/q(x)
 * 5. quadratic extension of a ring R with a polynomial x²-ax-b: formally it is isomorphic to R[x]/(x²-ax-b) 
 */

#endif


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

#endif //ACPC_PREPARATION_FFT_H

constexpr integer M=998244353;
using IK=cyclic<M>;


struct cyclic_polynomial
{
    inline static int degree=1;
    std::vector<IK> v;
    cyclic_polynomial(IK k=0)
    {
        v.resize(degree);
        v[0]=k;
    }
    cyclic_polynomial(std::vector<IK> _v):v(std::move(_v))
    {
        for(int i=degree;i<v.size();i++)
            v[i%degree]+=v[i];
        v.resize(degree);
    }

    cyclic_polynomial operator+(const cyclic_polynomial &P) const
    {
        std::vector<IK> R(degree);
        for(int i=0;i<degree;i++)
            R[i]=v[i]+P.v[i];
        return R;
    }

    cyclic_polynomial operator*(const cyclic_polynomial &P) const
    {
        auto R=karatsuba_multiplication(polynomial(v),polynomial(P.v));
        return R.p;
    }
    auto operator[](int i) const
    {
        return v[i];
    }
};

int main()
{

    int &k=cyclic_polynomial::degree,n;
    std::cin >> k >> n;
    k=1<<k;
    cyclic_polynomial A({0,1}),I(1);
    auto R=pow(I+A,n);
    for(int i=0;i<k;i++)
        std::cout << static_cast<integer>(R[i]) << ' ';
}
