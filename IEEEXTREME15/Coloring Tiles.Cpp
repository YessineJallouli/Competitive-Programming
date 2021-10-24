#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using natural=long long;
constexpr natural M=1e9+7;
using integer=natural;

template<long long n,bool is_prime=false>
class cyclic
{
public:
    cyclic(integer s=0):w((s+n)%n){}
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

using IK=cyclic<M,true>;

int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        int n,m,k;
        std::cin >> n >> m >> k;
        std::vector<std::vector<char>> G(n,std::vector<char>(m));
        for(auto &R:G) for(auto &g:R)
            std::cin >> g;
        std::vector<std::vector<std::vector<IK>>> D(m+1,std::vector<std::vector<IK>>(k+1,std::vector<IK>(k+1,0)));
        if(G[0][0]=='.' && G[1][0]=='.') for(int p=0;p<k;p++) for(int q=0;q<k;q++)
            D[0][p][q]=1;
        else if(G[0][0]=='#' && G[1][0]=='.') for(int q=0;q<k;q++)
            D[0][k][q]=1;
        else if(G[0][0]=='.' && G[1][0]=='#') for(int q=0;q<k;q++)
                D[0][q][k]=1;
        else D[0][k][k]=1;
        for(int i=1;i<m;i++)
        {
            if(G[0][i]=='.' && G[1][i]=='.') for (int c1 = 0; c1 < k; c1++) for (int c2 = 0; c2 < k; c2++)
                for (int t = 0; t <= k; t++) for (int s = 0; s <= k; s++)
                {
                    std::vector<int> A(k+1);
                    A[c1]++;
                    A[c2]++;
                    A[t]++;
                    A[s]++;
                    if(*std::max_element(A.begin(),A.end()-1)>2)
                        continue;
                    D[i][c1][c2]+=D[i-1][t][s];
                }
            else if(G[0][i]=='#' && G[1][i]=='.')for (int c2 = 0; c2 < k; c2++) for (int t = 0; t <= k; t++) for (int s = 0; s <= k; s++)
            {
                std::vector<int> A(k+1);
                A[c2]++;
                A[t]++;
                A[s]++;
                if(*std::max_element(A.begin(),A.end()-1)>2)
                    continue;
                D[i][k][c2]+=D[i-1][t][s];
            }
            else if(G[0][i]=='.' && G[1][i]=='#')for (int c1 = 0; c1 < k; c1++) for (int t = 0; t <= k; t++) for (int s = 0; s <= k; s++)
            {
                std::vector<int> A(k+1);
                A[c1]++;
                A[t]++;
                A[s]++;
                if(*std::max_element(A.begin(),A.end()-1)>2)
                    continue;
                D[i][c1][k]+=D[i-1][t][s];
            }
            else for (int t = 0; t <= k; t++) for (int s = 0; s <= k; s++)
                D[i][k][k]+=D[i-1][t][s];
        }
        IK R=0;
        for(int p=0;p<=k;p++) for(int q=0;q<=k;q++)
            R+=D[m-1][p][q];
        std::cout << R << '\n';
    }
    return false;
}
