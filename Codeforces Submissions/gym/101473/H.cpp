//
// Created by Rami on 20/05/2021.
//
#include <vector>
#include <iostream>
#include <iomanip>


template<long long m>
class cyclic_ring
{
    long long v;
public:
    cyclic_ring(long long s=0):v(s%m){}
    cyclic_ring operator+=(const cyclic_ring &O)
    {
        v+=O.v;
        v%=m;
        return *this;
    }

    cyclic_ring operator-=(const cyclic_ring &O)
    {
        v-=O.v;
        v%=m;
        return *this;
    }

    cyclic_ring operator*(long long O) const
    {
        return *this * cyclic_ring(O);
    }

    cyclic_ring operator*=(const cyclic_ring &O)
    {
        v*=O.v;
        v%=m;
        return *this;
    }

    cyclic_ring operator*(const cyclic_ring &O) const
    {
        auto S= *this;
        return S*= O;
    }


    cyclic_ring operator+(const cyclic_ring &O) const
    {
        auto S = *this;
        return S += O;
    }


    cyclic_ring operator-(const cyclic_ring &O) const
    {
        auto S=*this;
        return S -= O;
    }

    operator long long () const
    {
        return v;
    }

    operator long long&()
    {
        return v;
    }
};

template<typename T,long long n>
class square_matrix
{
private:
    std::vector<std::vector<T>> M;
public:
    square_matrix(const std::vector<std::vector<T>> &S):M(S){}
    square_matrix(long long s=0):M(n,std::vector<T>(n,0))
    {
        for(long long i=0;i<n;i++)
            M[i][i]=s;
    }
    square_matrix operator*(const square_matrix&O) const
    {
        square_matrix R;
        for(long long i=0;i<n;i++) for (long long k=0;k<n;k++) for(long long j=0;j<n;j++)
            R.M[i][j]+=M[i][k]*O.M[k][j];
        return R;
    }

    square_matrix& operator*=(const square_matrix &O)
    {
        return *this = (*this * O);
    }
    const std::vector<T>& operator[](long long i) const
    {
        return M[i];
    }
};

template<typename T>
T pow(const T& x,long long n)
{
    if(n==0)
        return T(1);
    else if(n==1)
        return x;
    long long s=n/2;
    T w=pow<T>(x,s);
    return w*w*pow<T>(x,n%2);
}

int main()
{
    long long N,K,L;
    std::cin >> N >> K >> L;
    square_matrix<cyclic_ring<1000000>,2> P({{K,L},{1,0}});
    auto R= pow(P,N/5)[1][0]*K+pow(P,N/5-1)[1][0]*L;
    std::cout << std::setfill('0') << std::setw(6)<< R;
}