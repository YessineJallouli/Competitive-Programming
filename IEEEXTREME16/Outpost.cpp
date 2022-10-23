//60%
#include <bits/stdc++.h>
using namespace std;

inline unsigned int bit_log(unsigned int n)
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

inline unsigned int bit_floor(unsigned int n)
{
    return 1<<bit_log(n);
}

inline unsigned int bit_ceil(unsigned int n)
{
    return 1<<(bit_log(n)+1);
}
template<typename T>
struct binary_operation
{
    template<typename H0,typename ...H>
    T operator()(const H0&a,const H&... b) const
    {
        if constexpr (sizeof...(b) == 0)
            return a;
        else return reduce(a,this->operator()(b...));
    }
    virtual T reduce(const T& a, const T& b) const = 0;
};

template<typename T>
struct max_t:public binary_operation<T>
{
    T reduce(const T&a,const T&b) const override
    {
        T c=neutral;
        for(int i=0;i<a.size();i++)
            c[i]=std::max(a[i],b[i]);
        return c;
    }

    inline static T neutral{0};
};



template<typename T>
struct min_t:public binary_operation<T>
{
    T reduce(const T&a,const T&b) const override
    {
        T c=neutral;
        for(int i=0;i<a.size();i++)
            c[i]=std::min(a[i],b[i]);
        return c;
    }

    inline static T neutral{};
};


template<typename T,typename O>
struct sparse_array
{
    inline static constexpr O F=O();
    int n,h;
    std::vector<std::vector<T>> S;
public:
    sparse_array(const std::vector<T>&A):n(bit_ceil(A.size())),h(bit_log(n)),S(h+1)
    {
        auto _A=A;
        _A.resize(n,O::neutral);
        int r=1;
        for(int i=h;i>=0;i--,r*=2)
            S[i].resize(n-r+1,O::neutral);
        for(int i=0;i<n;i++)
            S[h][i]=_A[i];
        r=1;
        for(int i=h-1;i>=0;i--,r*=2) for(int j=0;j<=n-2*r;j++)
                S[i][j]=F(S[i+1][j],S[i+1][j+r]);
    }

    T query(int l,int r) const
    {
        if(l>=r)
            return O::neutral;
        auto d=r-l;
        auto s=bit_floor(d);
        auto b=bit_log(s);
        return F(S[h-b][l],S[h-b][r-s]);
    }
};

template<typename R,typename O>
struct segment_tree
{
    std::vector<std::vector<R>> S;
    std::vector<R> A;
    int n,h;
    segment_tree(const std::vector<R> &_A):A(_A)
    {
        n=bit_ceil(A.size());
        A.resize(n,O::neutral);
        int m=n;
        h=0;
        while(m)
        {
            m/=2;
            h++;
        }
        S.resize(h);
        for(int i=0;i<h;i++)
            S[i].resize(1<<i);
        build();
    }

    void update(int i,R u)
    {
        A[i]=u;
        S[h-1][i]=u;
        int m=h-2;
        i/=2;
        while(m>=0)
        {
            S[m][i]=F(S[m+1][2*i],S[m+1][2*i+1]);
            m--;
            i/=2;
        }
    }

    R query(int l,int r)
    {
        return query(std::max(l,0),std::min(r,n),0,n,0);
    }
private:
    inline static constexpr O F=O();
    void build()
    {
        for(int i=0;i<n;i++)
            S.back()[i]=A[i];
        for(int i=h-2;i>=0;i--) for(int k=0;k<(1<<i);k++)
                S[i][k]=F(S[i+1][2*k],S[i+1][2*k+1]);
    }
    R query(int l,int r,int a,int b,int depth)
    {
        if(l>=r)
            return O::neutral;
        if(l==a && r==b)
            return S[depth][l>>(h-1-depth)];
        int mid=(a+b)/2;
        if(mid>r)
            return query(l,r,a,mid,depth+1);
        else if(mid<l)
            return query(l,r,mid,b,depth+1);
        else
            return F(query(l,mid,a,mid,depth+1),query(mid,r,mid,b,depth+1));
    }
};

using integer=std::int64_t;

using Array=std::vector<integer>;


int main()
{
    integer n,m,K;
    std::cin >> m >> n >> K;
//    if (m < n)
//        swap(m,n);
    std::vector<Array> A(n,std::vector<integer>(m));
    min_t<Array>::neutral.resize(m,std::numeric_limits<integer>::max());
    max_t<Array>::neutral.resize(m,std::numeric_limits<integer>::min());
    for(int j=0;j<m;j++) for(int i=0;i<n;i++)
            std::cin >> A[i][j];

    sparse_array<Array,min_t<Array>> U(A);
    sparse_array<Array,max_t<Array>> V(A);
    integer area=0;
    for(int a=0;a<m;a++) for(int b=a+1;b<=m;b++) for(int i=0;i<n;i++)
            {
                int p=i,q=n,r;
                while(p<=q)
                {
                    r=(p+q)/2;
                    auto Q2=V.query(i,r),Q1=U.query(i,r);
                    integer m1=Q1[a],m2=Q2[a];
                    for(int s=a+1;s<b;s++)
                    {
                        m1=std::min(m1,Q1[s]);
                        m2=std::max(m2,Q2[s]);
                    }
                    //integer m1=*std::min(Q1.begin()+a,Q1.begin()+b),m2=*std::max(Q2.begin()+a,Q2.begin()+b);
                    if(m2-m1<=K)
                    {
                        p=r+1;
                        area=std::max<integer>(area,static_cast<integer>(b-a)*static_cast<integer>(r-i));
                    }
                    else
                        q=r-1;
                }
            }
    std::cout << area << '\n';
}
