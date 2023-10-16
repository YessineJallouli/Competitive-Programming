#include <iostream>
#include <vector>
#include <cmath>

using integer = std::int64_t;

template<typename T>
struct binary_operation
{
    virtual T operator()(const T& a,const  T &b) const =0;
    template<typename H0,typename ...H>
    T operator()(const H0&a,const H&...b) const
    {
        return this->operator()(a,this->operator()(b...));
    }
};

struct min_t :public binary_operation<char>
{
    using T=char;
    T operator()(const T&a,const T&b) const override
    {
        return std::min(a,b);
    }
    inline static T neutral='9'+1;
};

unsigned int bit_log(unsigned int n)
{
    unsigned char a=0,b=30,r=0;
    while(a<=b)
    {
        auto c=(a+b)/2;
        if(n>>c)
            a=c+1;
        else
        {
            b=c-1;
            r=c-1;
        }
    }
    if((1<<(r-1))==n)
        return r-1;
    return r;
}

unsigned int bit_floor(unsigned int n)
{
    return 1<< bit_log(n);
}

unsigned int bit_ceil(unsigned int n)
{
    return 1<<(bit_log(n)+1);
}

template<typename T,typename O>
struct sparse_array
{
    inline static constexpr O F{};
    int n,h;
    std::vector<std::vector<T>> S;
public:
    sparse_array(const std::vector<T>&A):n(bit_ceil(A.size())),h(bit_log(n)),S(h+1)
    {
        int r=1;
        for(int i=h;i>=0;i--,r*=2)
            S[i].resize(n-r+1);
        for(int i=0;i<n;i++)
            S[h][i]=A[i];
        r=1;
        for(int i=h-1;i>=0;i--,r*=2) for(int j=0;j<=n-2*r;j++)
            S[i][j]=F(S[i+1][j],S[i+1][j+r]);
    }

    T query(int l,int r)
    {
        if(l>=r)
            return O::neutral;
        auto d=r-l;
        auto s= bit_floor(d);
        auto b= bit_log(s);
        return F(S[h-b][l],S[h-b][r-s]);
    }
};


int main()
{
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while(T--)
    {
        std::string S;
        std::cin >> S;
        int K;
        std::cin >> K;
        std::vector<char> A(S.begin(),S.end());
        sparse_array<char,min_t> Z(A);
        int a=0;
        int n=A.size();
        std::string R;
        if(Z.query(0,std::min(K+1,n))=='0')
        {
            char m=':';
            for(int i=0;i<std::min(K+1,n);i++)if(A[i]!='0')
                m=std::min(A[i],m);
            int s=0;
            while(s<n && A[s]!=m)
                s++;
            R.push_back(m);
            a=s+1;
            K-=s;
        }
        while(a<S.size() && K > 0)
        {
            int p=a,q=std::min(a+K+1,n),t;
            char x=Z.query(p,q);
            char m=x;
            int s=a;
            while(s<n && A[s]!=m)
                s++;
            R.push_back(m);
            K-=s-a;
            a=s+1;

        }
        for(;a<A.size();a++)
            R.push_back(A[a]);
        while(K>0 && ! R.empty()) {
            R.pop_back();
            K--;
        }
        std::cout << (R.empty()?"0":R) << '\n';
    }
}