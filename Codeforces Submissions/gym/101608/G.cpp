#include <iostream>
#include <vector>

using natural = std::uint32_t;


template <typename T>
struct binary_operation
{
    virtual T operator()(const T&a, const T&b) const =0;
    template<typename H0,typename ...H>
    T operator()(const H0&a,const H& ... b)
    {
        return this->operator()(a,this->operator()(b...));
    }
};


template<typename T>
struct or_t : public binary_operation<T>
{
    T operator()(const T&a,const T&b) const override
    {
        return a|b;
    }

    inline static T neutral=0;
};


natural bit_log(natural n)
{
    unsigned char a=0,b=32,r=0;
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

natural bit_floor(natural n)
{
    return 1<< bit_log(n);
}

natural bit_ceil(natural n)
{
    return 1<<(bit_log(n)+1);
}


template<typename T,typename  O>
class sparse_array
{
    inline static constexpr O F{};
    natural n,h;
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

    T query(int l,int r) const
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
    freopen("wifi.in", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while(T--)
    {
        natural n,v;
        std::cin >> n >> v;
        std::vector<natural> A(n);

        for(auto &a:A)
            std::cin >> a;
        sparse_array<natural,or_t<natural>> S(A);
        natural R=0;
        for(int i=0;i<n;i++)
        {
            natural r=0;
            int a=i,b=n,c;
            while(a<=b)
            {
                c=(a+b)/2;
                if(S.query(i,c)>v)
                    b=c-1;
                else
                {
                    a=c+1;
                    r=c-i;
                }
            }
            R=std::max(R,r);
        }
        std::cout << R << '\n';
    }
}