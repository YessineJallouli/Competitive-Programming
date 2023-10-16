#include <iostream>
#include <vector>
#include <numeric>

using real=__float128;

using vector=std::vector<real>;

struct matrix
{
    std::vector<std::vector<real>> M;
    inline static int n=2;
    matrix(real k=0):M(n,std::vector<real>(n))
    {
        for(int i=0;i<n;i++)
            M[i][i]=k;
    }
    matrix(const std::vector<std::vector<real>> &A):M(A)
    {

    }
    auto operator*(const matrix &O) const
    {
        matrix C;
        for(int i=0;i<n;i++) for(int k=0;k<n;k++) for(int j=0;j<n;j++)
            C.M[i][j]+=M[i][k]*O.M[k][j];
        return C;
    }

    auto& operator*=(const matrix &O)
    {
        return (*this = std::move((*this)*O));
    }

    auto& operator()(int k)
    {
        return M[k];
    }

    const auto& operator()(int k) const
    {
        return M[k];
    }

    vector operator*(const vector&u) const
    {
        vector v(n);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            v[i]+=M[i][j]*u[j];
        return v;
    }
};

template<typename R>
R pow(const R& x,std::uint64_t n)
{
    if(n==0)
        return R(1);
    else if(n==1)
        return x;
    auto y=pow(x,n/2);
    return y*y*pow(y,n%2);
}


constexpr int L=1e6;
using integer=std::uint64_t;
int main()
{
    std::uint64_t n;
    std::cin >> n;
    vector u={0,1};
    matrix M({{.5,.5},{1,0}});
    std::vector<long double> x(L+1);
    x[1]=1;
    for(int i=3;i<x.size();i++)
        x[i]=std::midpoint(x[i-1],x[i-2]);
    auto S=pow(M,n-1);
    std::cout.precision(10);
    std::cout << 100*x[std::min<integer>(L,n)] << ' ' << 100*(1-x[std::min<integer>(L,n)]) << '\n';

}