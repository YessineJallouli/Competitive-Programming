//
// Created by ramizouari on 23/10/2021.
//
#include <iostream>
#include <vector>
#include <set>
using integer=std::int64_t;
class dynamic_cyclic
{
public:
    explicit dynamic_cyclic(integer _n, integer s = 0);
    dynamic_cyclic(const dynamic_cyclic &o,integer s):dynamic_cyclic(o.n,s){}
    dynamic_cyclic& operator+=(const dynamic_cyclic& b);
    dynamic_cyclic& operator-=(const dynamic_cyclic& a);
    dynamic_cyclic& operator*=(const dynamic_cyclic& a);
    dynamic_cyclic& operator+=(integer b);
    dynamic_cyclic& operator-=(integer a);
    dynamic_cyclic& operator*=(integer a);
    dynamic_cyclic operator-() const;
    integer modulus() const
    {
        return n;
    }
    operator integer& ();
    operator const integer& () const;
    operator long long()const;
    bool is_zero() const;
    bool is_one() const;
    dynamic_cyclic inv()const;
    dynamic_cyclic operator/=(const dynamic_cyclic& a);

private:
    integer n;
    integer w;
};
dynamic_cyclic operator+(const dynamic_cyclic& a, const dynamic_cyclic& b);
dynamic_cyclic operator-(const dynamic_cyclic& a, const dynamic_cyclic& b);
dynamic_cyclic operator*(const dynamic_cyclic& a, const dynamic_cyclic& b);
dynamic_cyclic operator/(const dynamic_cyclic& a, const dynamic_cyclic& b);

dynamic_cyclic::dynamic_cyclic(integer _n, integer s):n(_n),w((n+s)%n)
{
}

using natural = std::uint64_t;


dynamic_cyclic& dynamic_cyclic::operator+=(const dynamic_cyclic& b)
{
    if (n != b.n)
        throw std::domain_error("incompatible modulus");
    w += b.w;
    w %= n;
    return *this;
}

dynamic_cyclic& dynamic_cyclic::operator-=(const dynamic_cyclic& a)
{

    if (n != a.n)
        throw std::domain_error("incompatible modulus");
    w -= a.w;
    w %= n;
    return *this;
}

dynamic_cyclic& dynamic_cyclic::operator*=(const dynamic_cyclic& a)
{
    if (n != a.n)
        throw std::domain_error("incompatible modulus");
    w *= a.w;
    w %= n;
    return *this;
}

dynamic_cyclic& dynamic_cyclic::operator+=(integer b)
{
    w += b;
    w %= n;
    return *this;
}

dynamic_cyclic& dynamic_cyclic::operator-=(integer a)
{
    w -=a;
    w %= n;
    return *this;
}

dynamic_cyclic& dynamic_cyclic::operator*=(integer a)
{
    w *= a;
    w %= n;
    return *this;
}

dynamic_cyclic dynamic_cyclic::operator-() const
{
    return dynamic_cyclic(*this,-w);
}

dynamic_cyclic::operator integer& ()
{
    return w;
}

dynamic_cyclic::operator const integer& () const
{
    return w;
}

dynamic_cyclic::operator long long() const
{
    return w;
}

bool dynamic_cyclic::is_zero() const
{
    return w==0;
}

bool dynamic_cyclic::is_one() const
{
    return w==1;
}

dynamic_cyclic dynamic_cyclic::inv() const
{
    //return dynamic_cyclic(*this,bezout<integer>(w,n).first);
    //return dynamic_cyclic(1,0);
}

dynamic_cyclic dynamic_cyclic::operator/=(const dynamic_cyclic& a)
{
    if (n != a.n)
        throw std::domain_error("incompatible modulus");
    return *this*=a.inv();
}

dynamic_cyclic operator+(const dynamic_cyclic& a, const dynamic_cyclic& b)
{
    auto c = a;
    return c+=b;
}

dynamic_cyclic operator-(const dynamic_cyclic& a, const dynamic_cyclic& b)
{
    auto c = a;
    return c -= b;
}

dynamic_cyclic operator*(const dynamic_cyclic& a, const dynamic_cyclic& b)
{
    auto c = a;
    return c *= b;
}

dynamic_cyclic operator/(const dynamic_cyclic& a, const dynamic_cyclic& b)
{
    auto c = a;
    return c /= b;
}


template<long long n,bool is_prime=false>
class cyclic
{
public:
    cyclic(integer s=0):w((s+n)%n){}
    cyclic(long long k):w((k+n)%n){}
    cyclic& operator+=(const cyclic& b)
    {
        w += b.w;
        w%=n;
        return *this;
    }
    cyclic& operator++()
    {
        return *this+=1;
    }
    cyclic operator--()
    {
        return *this-=1;
    }
    cyclic& operator-=(const cyclic& a)
    {
        w += (n - a.w);
        w %= n;
        return *this;
    }
    cyclic& operator*=(const cyclic& a)
    {
        w *= a.w;
        w %= n;
        return *this;
    }


    cyclic& operator+=(int b)
    {
        return *this+=cyclic(b);
    }
    cyclic& operator-=(int a)
    {
        return *this-=cyclic(a);
    }
    cyclic& operator*=(int a)
    {
        return *this*=cyclic(a);
    }
    cyclic operator-() const
    {
        return cyclic(n - w);
    }
    operator integer& () { return w; }
    operator const integer& () const{ return w; }

    cyclic inv()const
    {
        if constexpr (is_prime)
            return pow(*this, n - 2);
      //  else return bezout<integer>(w, n).first;
    }

    cyclic operator/=(const cyclic& a)
    {
        return *this *= a.inv();
    }
private:
    integer w;
};
template<long long n,bool is_prime>
cyclic<n, is_prime> operator+(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c += b;
}
template<long long n,bool is_prime >
cyclic<n,is_prime> operator-(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c -= b;
}
template<long long n,bool is_prime>
cyclic<n, is_prime> operator*(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c *= b;
}

template<long long n, bool is_prime>
cyclic<n, is_prime> operator/(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c /= b;
}

template<typename A>
A pow(const A& u, long long n)
{
    if (n == 0)
        return unit(u);
    else if (n == 1)
        return u;
    A r = pow(u, n / 2);
    r *= r;
    return r * pow(u, n % 2);
}

dynamic_cyclic pow(const dynamic_cyclic&u, long long n)
{
    if (n == 0)
        return dynamic_cyclic(u.modulus(),1);
    else if (n == 1)
        return u;
    dynamic_cyclic r = pow(u, n / 2);
    r *= r;
    return r * pow(u, n % 2);
}

int main()
{
    integer p,q,n,m;
    std::cin >> p >> q>> n >> m;
    dynamic_cyclic w(m,p),R(m,0);
    for(int i=1;i<=n;i++)
    {
        R=R+w*pow(dynamic_cyclic(m,i),q);
        w*=p;
    }
    std::cout << R;
}
