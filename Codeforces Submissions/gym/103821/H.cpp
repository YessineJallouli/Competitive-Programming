#include <iostream>
#include <vector>
#include <array>

using integer=std::int64_t;

template<integer mod>
class cyclic
{
    integer n;
public:
    inline static constexpr integer m = mod;
    cyclic(int o=0):n((o+m)%m){}
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

    auto inv() const
    {
        return pow(*this,m-2);
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

constexpr int N_max=2e5;

constexpr integer M=1e9+7;
using IK=cyclic<M>;

int main()
{
    std::array<IK,N_max> T;
    T[1]=1;
    T[0]=0;
    for(int i=2;i<N_max;i++)
        T[i]=T[i-1]+T[i-2]+1;
    int Q;
    std::cin >> Q;
    while(Q--)
    {
        int n;
        std::cin >> n;
        std::cout << (integer)T[n] << '\n';
    }
}