#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <bitset>


namespace linear_algebra
{
    template<typename R>
    struct vector
    {
        inline static int n;
        std::vector<R> u;
    public:
        vector():u(n){}
        vector(const std::vector<R>&u):u(u){}
        vector(std::vector<R>&&u):u(std::move(u)){}
        static void set_dimension(int _n)
        {
            n=_n;
        }

        const auto& operator[](size_t k) const
        {
            return u[k];
        }

        auto& operator[](size_t k)
        {
            return u[k];
        }

        auto &operator+=(const vector &A)
        {
            for(int i=0;i<n;i++)
                u[i]+=A.u[i];
            return *this;
        }

        auto &operator-=(const vector &A)
        {
            for(int i=0;i<n;i++)
                u[i]-=A.u[i];
            return *this;
        }

        auto operator+(const vector &A)
        {
            vector C=*this;
            return C+=A;
        }

        auto operator-(const vector &A)
        {
            vector C=*this;
            return C-=A;
        }

        auto& operator*=(const R &k)
        {
            for(auto &a:u)
                a*=k;
            return *this;
        }
        auto& operator/=(const R &k)
        {
            for(auto &a:u)
                a/=k;
            return *this;
        }

        auto operator-()const
        {
            auto C=*this;
            for(auto &a:C.u)
                a=-a;
            return C;
        }

        auto begin()
        {
            return u.begin();
        }

        auto end()
        {
            return u.end();
        }

        auto begin() const
        {
            return u.begin();
        }

        auto end() const
        {
            return u.end();
        }
    };

    template<typename R>
    auto operator*(const R&k, const vector<R> &u)
    {
        auto v=u;
        v*=k;
        return v;
    }


    template<typename R>
    struct matrix
    {
        inline static int n;
        std::vector<std::vector<R>> M;
    public:
        matrix(R k=0):M(n,std::vector<R>(n))
        {
            for(int i=0;i<n;i++)
                M[i][i]=k;
        }
        matrix(const std::vector<std::vector<R>>&M):M(M){}
        matrix(std::vector<std::vector<R>>&&u):M(std::move(M)){}
        static void set_dimension(int _n)
        {
            n=_n;
        }


        auto T() const
        {
            matrix A;
            for(int i=0;i<n;i++) for(int j=0;j<n;j++)
                    A[i][j]=M[j][i];
            return A;
        }

        const auto& operator[](size_t k) const
        {
            return M[k];
        }

        auto& operator[](size_t k)
        {
            return M[k];
        }

        auto &operator+=(const matrix &A)
        {
            for(int i=0;i<n;i++) for(int j=0;j<n;j++)
                    M[i][j]+=A.M[i][j];
            return *this;
        }

        auto &operator-=(const matrix &A)
        {
            for(int i=0;i<n;i++)
                M[i]+=A.M[i];
            return *this;
        }

        auto operator+(const matrix &A)
        {
            vector C=*this;
            return C+=A;
        }

        auto operator-(const matrix &A)
        {
            vector C=*this;
            return C-=A;
        }

        auto operator*(const matrix &A)
        {
            matrix C;
            for(int i=0;i<n;i++) for(int k=0;k<n;k++) for(int j=0;j<n;j++)
                        C.M[i][j]+=M[i][k]*A.M[k][j];
            return C;
        }


        auto& operator*=(const matrix &A)
        {
            return *this = std::move((*this)*A);
        }

        vector<R> operator*(const vector<R> &u)
        {
            vector<R> v;
            for(int i=0;i<n;i++) for(int j=0;j<n;j++)
                    v[i]+=M[i][j]*u[j];
            return v;
        }

        auto& operator*=(const R &k)
        {
            for(auto &P:M) for(auto &a:P)
                    a*=k;
            return *this;
        }
        auto& operator/=(const R &k)
        {
            for(auto &P:M) for(auto &a:P)
                    a/=k;
            return *this;
        }

        auto operator-()const
        {
            auto C=*this;
            for(auto &P:C.u) for(auto &a:P)
                    a=-a;
            return C;
        }

        auto begin()
        {
            return M.begin();
        }

        auto end()
        {
            return M.end();
        }

        auto begin() const
        {
            return M.begin();
        }

        auto end() const
        {
            return M.end();
        }

        matrix inv() const
        {
            int n=this->n,m=this->n;
            matrix P=*this,Q=1;
            for(int i=0;i<n;i++)
            {
                int p=i;
                while(p<n && P.M[p][i]==R(0))
                    p++;
                if(p==n)
                    continue;
                std::swap(P.M[p], P.M[i]);
                std::swap(Q.M[p],Q.M[i]);
                R w=P.M[i][i];
                for(int j=i+1;j<n;j++)
                {
                    R r=P.M[j][i]/w;
                    for (int k = 0; k < m; k++)
                    {
                        P.M[j][k] -= r*P.M[i][k];
                        Q.M[j][k] -= r*Q.M[i][k];
                    }
                }
            }
            for(int i=n-1;i>=0;i--)
            {
                R w=P.M[i][i];
                for(int j=0;j<n;j++)
                    Q.M[i][j]/=w;
                for(int k=i-1;k>=0;k--)
                {
                    R r=P.M[k][i];
                    for (int j = 0; j < n; j++)
                        Q.M[k][j] -= r*Q.M[i][j];
                }
            }
            return Q;
        }

        vector<R> solve(vector<R> u)
        {
            auto &A=u;
            int &n=this->n,&m=n;
            matrix P=*this;
            for(int i=0;i<n;i++)
            {
                int p=i;
                while(p<n && P.M[p][i]==0)
                    p++;
                if(p==n)
                    continue;
                std::swap(P.M[p],P.M[i]);
                std::swap(A[p],A[i]);
                R w=P.M[i][i];
                for(int j=i+1;j<n;j++)
                {
                    if(w==0)
                        continue;
                    R r=P.M[j][i]/w;
                    for(int k=0;k<m;k++)
                        P.M[j][k]-=r*P.M[i][k];
                    A[j]-=r*A[i];
                }
            }
            for(int i=n-1;i>=0;i--)
            {
                R w=P.M[i][i];
                if(w==0)
                    continue;
                A[i]/=w;
                for(int k=i-1;k>=0;k--)
                {
                    R r=P.M[k][i];
                    A[k]-=r*A[i];
                }
            }
            return A;
        }
    };

    template<typename R>
    auto operator*(const R&k, const matrix<R> &u)
    {
        auto v=u;
        v*=k;
        return v;
    }

}




using real=double;
using integer=std::int64_t;

struct uniform_family
{
    inline static constexpr integer M=1e9+7;
    inline static std::random_device dev;
    inline static std::mt19937_64 g{dev()};
    std::uniform_int_distribution<integer> d;
    integer a=d(g),b=d(g);
public:
    auto operator()(int x) const noexcept
    {
        return (a*x+b)%M;
    }
};


typedef long long ll;
using namespace std;

const int N = 2e5+7;
int mx[N];
int dp[N];

void dfs(int u, const vector<vector<int>> &tree, int p = -1) {
    mx[u] = 0;
    for (auto v : tree[u]) {
        if (v == p)
            continue;
        dfs(v,tree, u);
        mx[u] = max(1+mx[v], mx[u]);
    }
}

void dfs1(int u, const vector<vector<int>> &tree, int p = -1, int m = 0) {
    dp[u] = max(m, mx[u]);
    multiset<int> st;
    st.insert(-(m));
    for (auto v : tree[u]) {
        if (v == p)
            continue;
        st.insert(-(mx[v]+1));
    }
    for (auto v : tree[u]) {
        if (v == p)
            continue;
        st.erase(st.find(-(mx[v]+1)));
        dfs1(v,tree,u, -*st.begin()+1);
        st.insert(-(mx[v]+1));
    }
}


std::vector<bool> overflow(const std::vector<vector<int>> &tree,const int K)
{
    for (int i = 0; i < tree.size(); i++)
        mx[i] = dp[i] = 0;
    dfs(1,tree);
    dfs1(1, tree);
    vector<bool> ans(tree.size()-1);
    for (int i = 1; i < tree.size(); i++) {
        ans[i-1] = (dp[i] > K);
    }
    return ans;
}

constexpr bool approximation=false;

int main()
{
    int T;
    std::ios_base::sync_with_stdio(false);
    std::cin >> T;
    while(T--)
    {
        int C,K;
        std::cin >> C >> K;
        namespace linalg=linear_algebra;
        std::vector<real> P(C);
        for(int j=0;j<C;j++)
        {
            int n;
            std::cin >> n;
            std::vector<std::vector<int>> tree(n+1);
            for(int i=2;i<=n;i++)
            {
                int a;
                std::cin >> a;
                tree[a].push_back(i);
                tree[i].push_back(a);
            }
            auto D= overflow(tree,K);
            int r=0;
            for(auto d:D) if(!d)
                    r++;
            P[j]=static_cast<real>(r)/n;
        }
        linalg::vector<real>::n=C;
        linalg::matrix<real>::n=C;
        linalg::vector<real> v;
        linalg::matrix<real> M;
        for(int i=0;i<C;i++)
        {
            v[i]=P[i]+4*(1-P[i]);
            M[i][i]+=1;
            if(i<C-1)
                M[i][i+1]-=P[i];
            M[i][0]-=(1-P[i]);
        }

        //auto I=M.inv();
        linalg::vector<real> u;
        if constexpr (approximation)
        {
            auto M_T=M.T();
            auto J=M_T*M,J_inv=J.inv();
            real r=0;
            for(int i=0;i<C;i++) for(int j=0;j<C;j++)
                    r+=J[i][j]*J[i][j];
            auto grad=[&M_T,&M,&v](const linalg::vector<real> &u){
                return M_T*(M*u-v);
            };
            real =0.2;
            for(int i=0;i<1600;i++)
                u-=*grad(u);
        }
        else u=M.solve(v);
        std::cout.precision(4);
        std::cout << std::fixed << u[0] << '\n';
    }
}