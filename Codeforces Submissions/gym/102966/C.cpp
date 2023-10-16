//
// Created by ramizouari on 12/03/2021.
//

#include <iostream>
#include <vector>

class square_matrix
{
    int n;
    std::vector<std::vector<double>> M;
public:
    struct ID{};
    square_matrix(int _n):M(_n,std::vector<double>(_n,0)),n(_n){}
    square_matrix(const std::vector<std::vector<double>>&v):M(v),n(v.size())
    {
        if(M.empty()||M.back().size()!=M.size())
            throw std::logic_error("Nope2");
    }
    square_matrix(int n,const square_matrix::ID &):square_matrix(n)
    {
        for(int i=0;i<n;i++)
            M[i][i]=1;
    }
    square_matrix operator*(square_matrix const &A) const
    {
        square_matrix R(n);
        if(A.n!=n)
            throw std::logic_error("Nope");
        for(int i=0;i<n;i++) for(int k=0;k<n;k++) for(int j=0;j<n;j++)
            R.M[i][j]+=M[i][k]*A.M[k][j];
        return R;
    }
    square_matrix& operator*=(square_matrix const &A)
    {
        return *this = (*this)*A;
    }
    std::vector<double> operator*(std::vector<double> &v)
    {
        std::vector<double> R(n,0);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            R[i] += M[i][j]*v[j];
        return R;
    }
    int dimension() const
    {
        return n;
    }
    square_matrix transpose() const {
        square_matrix R(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                R.M[j][i] = M[i][j];
        return R;
    }
};
using ID=square_matrix::ID;
square_matrix pow(const square_matrix &A,int p)
{
        if(p<=1)
            return p?A:square_matrix(A.dimension(),ID());
        int s= p/2;
        auto Q=pow(A,s);
        return (Q*Q)*pow(A,p%2);
}

int main()
{
    using namespace std;
    int n,m;
    cin >>  n >> m;
    vector<double> v(n,0);
    v[0]=1;
    std::vector<std::vector<double>> M(n,std::vector<double>(n,0));
    for(auto &row :M) for (auto &u:row)
        cin >> u;
    auto R=pow(square_matrix(M),m).transpose();
    for(const auto &s:R*v)
        cout << s << '\n';
    return false;
}