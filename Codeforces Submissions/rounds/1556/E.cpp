#include <iostream>

//
// Created by ramizouari on 02/08/2021.
//

#include <vector>
#include <numeric>
#include <set>
#include <map>
#include <algorithm>
#include <optional>

int bit_ceil(int n)
{
    int m=1;
    while(n>>=1)
        m++;
    return 1<<(m+1);
}

template<typename T>
struct plus_t
{
    T operator()(const T&a,const T&b) const
    {
        return a+b;
    }
    inline static T neutral=T();
};


template<typename T>
struct max_t
{
    T operator()(const T&a,const T&b) const
    {
        return std::max(a,b);
    }
    inline static T neutral=T();
};

template<typename T>
struct min_t
{
    T operator()(const T&a,const T&b) const
    {
        return std::min(a,b);
    }
    inline static T neutral=T();
};


template<typename T>
struct multiplies_t
{
    T operator()(const T&a,const T&b) const
    {
        return a*b;
    }
    inline static T neutral=T(1);
};

template<typename T>
struct gcd_t
{
    T operator()(const T&a,const T&b) const
    {
        return std::gcd(a,b);
    }
    inline static T neutral=T();
};


template<typename T>
struct lcm_t
{
    T operator()(const T&a,const T&b) const
    {
        return std::lcm(a,b);
    }
    inline static T neutral=T(1);
};

template<typename T,typename O=plus_t<T>>
class segment_tree
{
    inline static constexpr O F=O();
    std::vector<T> A;
    std::vector<std::vector<T>> S;
    int size;
    void rec_build(int depth,int a,int L)
    {
        S[depth][a]=F.neutral;
        if(L==1)
        {
            S[depth][a]=A[a];
            return;
        }
        if(L>1)
        {
            rec_build(depth+1,2*a,L/2);
            rec_build(depth+1,2*a+1,L/2);
            S[depth][a]=F(S[depth+1][2*a],S[depth+1][2*a+1]);
        }
    }
    void build()
    {
        int n=A.size(),m=1;
        S.clear();
        while(m<=n)
        {
            S.push_back(std::vector<T>(m));
            m*=2;
        }
        rec_build(0,0,A.size());
    }
public:
    segment_tree(std::vector<T> &&_A):A(std::move(_A))
    {
        size=A.size();
        A.resize(bit_ceil(A.size()),F.neutral);
        build();
    }
    segment_tree(const std::vector<T> &_A):A(_A)
    {
        size=A.size();
        A.resize(bit_ceil(A.size()),F.neutral);
        build();
    }

    T query(int l,int r,int a,int b,int depth) const
    {
        if(l>=r)
            return F.neutral;
        int c=(a+b)/2;
        if(c<l)
            return query(l,r,c,b,depth+1);
        if(c>r)
            return query(l,r,a,c,depth+1);
        T R;
        if(a==l && r==b)
            R=S[depth][a>>(S.size()-depth-1)];
        else
            R= F(query(l,c,a,c,depth+1),query(c,r,c,b,depth+1));

        return R;
    }
    T query(int l,int r) const
    {
        return query(std::max(l,0),std::min<int>(r,A.size()),0,A.size(),0);
    }

    void update(
            int p,const T &r)
    {
        int m=S.size()-1;
        S[m][p]=r;
        p/=2;
        m--;
        while(m>=0)
        {
            S[m][p]=F(S[m+1][2*p],S[m+1][2*p+1]);
            m--;
            p/=2;
        }
    }
    void push_back(const T&r)
    {
        if(size==A.size())
        {
            A.resize(2*size);
            A[size]=r;
            build();
        }
        else
        {
            A[size]=r;
            update(size,r);
        }
        size++;
    }

    void pop_back()
    {
        int m=bit_ceil(size-1);
        if(m==size-1)
        {
            size--;
            A.resize(size);
            build();
        }
        else
        {
            update(size-1,F.neutral);
            size--;
        }
    }
};

using natural = long long;

template<typename R>
std::optional<R> operator+(const std::optional<R>& a,const R& b)
{
    if(a)
        return a.value()+b;
    return b;
}

template<typename R>
std::optional<R> operator+(const std::optional<R>& a,const std::optional<R>& b)
{
    if(b)
        return a+b.value();
    return a;
}

struct F_max
{
    natural max_prefix,max_suffix,max_sum,total_sum;
    F_max(natural r=0):max_prefix(r),max_suffix(r),max_sum(r),total_sum(r){}

    F_max operator+(F_max O) const
    {
        F_max R;
        R.total_sum=total_sum+O.total_sum;
        R.max_prefix=std::max(max_prefix,total_sum+O.max_prefix);
        R.max_suffix=std::max(O.max_suffix,max_suffix+O.total_sum);
        R.max_sum=std::max({max_suffix+O.max_prefix,max_sum,O.max_sum});
        return R;
    }
};

struct F_min
{
    natural min_prefix,min_suffix,min_sum,total_sum;
    F_min(natural r=0):min_prefix(r),min_suffix(r),min_sum(r),total_sum(r){}
    F_min operator+(F_min O) const
    {
        F_min R;
        R.total_sum=total_sum+O.total_sum;
        R.min_prefix=std::min(min_prefix,total_sum+O.min_prefix);
        R.min_suffix=std::min(O.min_suffix,min_suffix+O.total_sum);
        R.min_sum=std::min({min_suffix+O.min_prefix,min_sum,O.min_sum});
        return R;
    }
};


struct F
{
    std::optional<F_min> u;
    std::optional<F_max> v;
    F() {}
    F(natural r):u(r),v(r){}
    F(std::optional<F_min> a,std::optional<F_max> b ):u(a),v(b){}
    F operator+(F O) const
    {
        F R{u+O.u,v+O.v};
        return R;
    }
};

int main()
{
    int n,q;
    std::cin >> n >> q;
    std::vector<natural> A(n),B(n),C(n);
    std::vector<F> S(n);
    for(auto &a:A)
        std::cin >> a;
    for(auto &b:B)
        std::cin >> b;
    for(int i=0;i<n;i++) {
        C[i] = B[i] - A[i];
        S[i]=C[i];
    }
    segment_tree<F> U(S);
    for(int i=0;i<q;i++)
    {
        int l,r;
        std::cin >> l >> r;
        l--;
        r--;
        auto [u,v]=U.query(l,r+1);
        if(u.value().min_prefix<0 || v.value().max_suffix>0 || u.value().total_sum!=0)
        {
            std::cout << -1 << ' ';
            continue;
        }
        auto R=std::max(-u.value().min_sum,v.value().max_sum);
        std::cout << R << ' ';
    }
}