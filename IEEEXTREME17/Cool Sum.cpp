//100%
#include <iostream>
#include <vector>
//
// Created by ASUS on 30/11/2021.
//
 
 
#include <cstdint>
#include <utility>
//
// Created by ramizouari on 01/12/2021.
//
 
 
 
#include <complex>
#include <functional>
using natural = std::uint64_t;
using integer = std::int64_t;
using real = long double;
using IR=real;
using IC= std::complex<IR>;
constexpr real epsilon=1e-7;
 
template<typename R>
R commutator(R a,R b)
{
    return a*b-b*a;
}
 
template<typename M,typename G=typename M::base_field>
M conj(M a)
{
    if constexpr (std::is_same_v<G, IC>)
    {
        if constexpr (std::is_same_v<G, M>)
            return std::conj(a);
        else for (auto& s : a)
                s = conj<typename std::remove_reference<decltype(s)>::type, G>(s);
    }
    return a;
}
 
template<typename R,typename ...StructureMetaData>
R pow(R a, long long n,StructureMetaData ... meta_info)
{
    if(n==0)
        return R(1,meta_info...);
    else if(n==1)
        return a;
    auto s=pow(a,n/2);
    return n%2?s*s*a:s*s;
}
 
template<typename R>
bool is_zero(const R&a)
{
    return a==R{};
}
 
inline bool is_zero(const IC&a)
{
    return std::abs(a) < epsilon;
}
 
inline bool is_zero(const real &a)
{
    return std::abs(a) < epsilon;
}
 
template<typename R>
R gcd(R a,R b)
{
    if(a<b)
        std::swap(a,b);
    R q,tmp;
    while(!is_zero(b))
    {
        q=a/b;
        tmp=b;
        b=a-b*q;
        a=tmp;
    }
    return a;
}
 
template<typename R>
R lcm(const R &a,const R &b)
{
    return a*b/gcd(a,b);
}
 
template<typename R=integer>
struct egcd_t
{
    R a,b,d;
};
 
template<typename R>
egcd_t<R> egcd(R a,R b)
{
    if(a<b)
    {
        auto e = egcd(b, a);
        std::swap(e.a,e.b);
        return e;
    }
    R q,s1=1,s2=0,t1=0,t2=1,tmp;
    while(!is_zero(b))
    {
        q=a/b;
        tmp=s2;
        s2=s1-q*s2;
        s1=tmp;
        tmp=t2;
        t2=t1-q*t2;
        t1=tmp;
        tmp=b;
        b=a-b*q;
        a=tmp;
    }
    return {s1,t1,a};
}
 
template<typename R>
std::pair<R,R> bezout(R a, R b)
{
    auto [u,v,_]=egcd(a,b);
    return {u,v};
}
 
template<typename B>
B next_gray(B n)
{
    return n^(n>>1);
}
 
template<typename F,typename R>
std::pair<integer,integer> floyd_functional_cycle(F && f,R x0)
{
    /*
     * Find a period
     * */
    R x=x0,y=x;
    integer m=0;
    do
    {
        x=f(x);
        y=f(f(y));
        m++;
    }while(y!=x);
    /*
     * Find offset
     * */
    x=x0,y=x;
    for(int i=0;i<m;i++)
        y=f(y);
    int offset=0;
    while(x!=y)
    {
        x=f(x);
        y=f(y);
        offset++;
    }
 
    /*
     * Find fundamental period
     * */
    y=f(x);
    integer period=1;
    while(x!=y) {
        y = f(y);
        period++;
    }
    return std::make_pair(period,offset);
}
 
 
template<typename F,typename R>
integer functional_period(F &&f, R x)
{
    /*
    * Find a period
    * */
    R y=x;
    integer m=0;
    do
    {
        x=f(x);
        y=f(f(y));
        m++;
    }while(y!=x);
    return m;
}
 
 
//ACPC_PREPARATION_ABSTRACT_ALGEBRA_H
#include <random>
#include <unordered_map>
//
// Created by ASUS on 01/12/2021.
//
 
 
#include <cstdint>
#include <vector>
#include <map>
#include <numeric>
#include <cmath>
#include <stack>
#include <algorithm>
 
using couple =std::pair<integer,integer>;
 
class factoriser
{
    int n;
    std::vector<integer> p_list,smallest_d;
    std::vector<std::vector<integer>> p_factors;
    std::vector<std::vector<integer>> d_list;
    std::vector<std::vector<couple>> p_dec;
 
    void divisors_list_rec(integer n,std::vector<integer> &D,const std::vector<integer> &P, int o=0)
    {
        auto r=P.size();
        for(int i=o;i<r;i++) if(n%P[i]==0)
                divisors_list_rec(n/P[i],D,P,i);
        D.push_back(n);
 
    }
public:
    factoriser(int _n):n(_n),smallest_d(n+1),p_factors(n+1),d_list(n+1),p_dec(n+1)
    {
        p_list.reserve(n/log(n));
        std::vector<bool> is_prime(n+1,true);
        for(integer i=2;i<=n;i++) if(is_prime[i])
            {
                p_list.push_back(i);
                smallest_d[i]=i;
                p_factors[i]={i};
                for(integer j=2*i;j<=n;j+=i)
                {
                    if(is_prime[j])
                    {
                        smallest_d[j] = i;
                        is_prime[j]=false;
                    }
                    p_factors[j].push_back(i);
                }
            }
    }
 
    [[nodiscard]] const auto& prime_factors(integer m) const
    {
        static std::vector<integer> holder;
        if(m<=n)
            return p_factors[m];
        auto p=smallest_divisor(m);
        holder={};
        while(m>1)
        {
            auto p= smallest_divisor(m);
            if(holder.empty()||holder.back()!=p)
                holder.push_back(p);
            m/=p;
        }
        return holder;
    }
 
    const auto& prime_decomposition(integer m)
    {
        static std::vector<std::pair<integer,integer>> holder;
        if(m<=n)
        {
            integer r=m;
            if(p_dec[m].empty())
            {
                for(auto p: prime_factors(m))
                {
                    int s=0;
                    while(r%p==0)
                    {
                        r/=p;
                        s++;
                    }
                    p_dec[m].emplace_back(p,s);
                }
            }
            return p_dec[m];
        }
        else
        {
            holder.clear();
            integer r=m;
            for(auto p: prime_factors(m))
            {
                int s=0;
                while(r%p==0)
                {
                    r/=p;
                    s++;
                }
                holder.emplace_back(p,s);
            }
            return holder;
        }
    }
 
    const auto& divisors_list(integer m)
    {
        static std::vector<integer> holder;
        static std::map<integer,std::vector<integer>> cache;
        if(m<=n)
        {
            if (d_list[m].empty())
                divisors_list_rec(m, d_list[m], p_factors[m]);
            return d_list[m];
        }
        else
        {
            if(cache.count(m))
                return cache[m];
            divisors_list_rec(m,holder, prime_factors(m));
            cache[m]=holder;
            return cache[m];
        }
    }
 
    const auto& divisors_list_sorted(integer m)
    {
        static std::vector<integer> holder;
        static std::map<integer,std::vector<integer>> cache;
        if(m<=n)
        {
            if (d_list[m].empty())
            {
                divisors_list_rec(m, d_list[m], p_factors[m]);
                std::sort(d_list[m].begin(),d_list[m].end());
            }
            return d_list[m];
        }
        else
        {
            if(cache.count(m))
                return cache[m];
            divisors_list_rec(m,holder, prime_factors(m));
            std::sort(holder.begin(),holder.end());
            cache[m]=holder;
            return cache[m];
        }
    }
 
    [[nodiscard]] integer smallest_divisor(integer m) const
    {
        if(m<=n)
            return smallest_d[m];
        integer L=std::ceil(std::sqrt(m));
        for(auto p:p_list)
        {
            if(p>L)
                break;
            else if(m%p==0)
                return p;
        }
        return m;
    }
 
    [[nodiscard]] bool is_prime(integer m) const
    {
        if(m<n)
            return m>1 && smallest_d[m]==m;
        else
        {
            integer L=std::ceil(std::sqrt(m));
            for(auto p:p_list)
                if(m%p==0)
                    return false;
                else if(p>L)
                    break;
            return true;
        }
    }
 
    integer totient_rec(integer n,const std::vector<integer> &P, integer o=0)
    {
        if(n==0)
            return 0;
        integer S=n;
        for(int i=o;i<P.size();i++)
            S-= totient_rec(n/P[i],P,i+1);
        return S;
    }
 
    integer totient(integer n)
    {
        integer R=1;
        for(auto [p,m]: prime_decomposition(n))
            R*=pow(p,m-1)*(p-1);
        return R;
    }
 
    integer totient(integer n,integer m)
    {
        if(n==0)
            return 0;
        auto r=m%n;
        auto P= prime_factors(n);
        return (m/n)*totient(n)+totient_rec(r,P);
    }
 
    integer carmichael_totient(integer n)
    {
        integer R=1;
        for(auto [p,m]: prime_decomposition(n))
        {
            if(p==2 && m>2)
                R=std::lcm(R,pow(p,m-2));
            else R=std::lcm(R,pow(p,m-1)*(p-1));
        }
        return R;
    }
 
    integer divisors_count(integer n)
    {
        integer R=1;
        for(auto [_,m]: prime_decomposition(n))
            R*=(m+1);
        return R;
    }
 
    integer divisor_function(integer n,integer s)
    {
        if(s==0)
            return divisors_count(n);
        integer R=1;
        for(auto [p,m]: prime_decomposition(n))
            R*=(pow(p,(m+1)*s)-1)/(pow(p,s)-1);
        return R;
    }
 
    integer divisors_sum(integer n)
    {
        return divisor_function(n,1);
    }
 
    [[nodiscard]] integer count_primes() const
    {
        return p_list.size();
    }
 
    [[nodiscard]] const auto& prime_list() const
    {
        return p_list;
    }
 
    void generate_radicals_rec(std::vector<integer> &R,integer a,integer L,int o=0)
    {
        for(int s=o;s<p_list.size() && a*p_list[s] <= L;s++)
        {
            R.push_back(a*p_list[s]);
            generate_radicals_rec(R,a*p_list[s],L,s+1);
        }
    }
 
    std::vector<integer> genereate_radicals(integer L)
    {
        std::vector<integer> radicals;
        generate_radicals_rec(radicals,1,L);
        return radicals;
    }
 
};
 
inline integer chinese_remainder(const std::vector<std::pair<integer,integer>> &S)
{
    std::stack<std::pair<integer,integer>> Q;
    for(auto s:S)
        Q.push(s);
    while(Q.size() > 1)
    {
        auto [a1,p1]=Q.top();
        Q.pop();
        auto [a2,p2]=Q.top();
        Q.pop();
        auto [k1,k2]=bezout(p1,p2);
        k2*=(a1-a2);
        Q.push({(k2*p2+a2)%(p1*p2),p1*p2});
    }
    return Q.top().first;
}
 
inline integer chinese_remainder(const std::vector<integer>& A,const std::vector<integer>& P)
{
    std::vector<std::pair<integer,integer>> S;
    int n=A.size(),m=P.size();
    S.reserve(n);
    for(int i=0;i<n;i++)
        S.emplace_back(A[i],P[i]);
    return chinese_remainder(S);
}
 
 
 
//
// Created by ramizouari on 01/12/2021.
//
 
 
//
// Created by ramizouari on 01/12/2021.
//
 
 
#include <vector>
#include <map>
 
 
 
/*
 * This header contains a list of usual ring extensions:
 * 1. field of fractions for an integral ring R
 * 2. nilpotent extension of a ring R: formally it is isomorphic to R[x]/x^k where k is the nilpotence index
 * 3. idempotent extention of a ring R: formally it is isomorphic to R[x]/(x^k-x^(k-1)) where k is the idempotence index
 * 4. ring extension of a ring R with a polynomial q: formally it is isomorphic to R[x]/q(x)
 * 5. quadratic extension of a ring R with a polynomial x²-ax-b: formally it is isomorphic to R[x]/(x²-ax-b)
 */
 
 
class d_cyclic
{
    integer n;
public:
    inline static integer m=1;
    inline static bool assume_prime=true;
    d_cyclic(integer o=0):n((o+m)%m){}
    bool operator==(int O) const
    {
        return n==(m+O)%m;
    }
 
    bool operator!=(int O) const
    {
        return n!=(m+O)%m;
    }
 
    bool operator==(d_cyclic O) const
    {
        return n==O.n;
    }
 
    bool operator!=(d_cyclic O) const
    {
        return n!=O.n;
    }
 
    auto& operator+=(const d_cyclic &O)
    {
        n=(n+O.n)%m;
        return *this;
    }
    auto& operator-=(const d_cyclic &O)
    {
        n=(n+m-O.n)%m;
        return *this;
    }
 
    auto& operator*=(const d_cyclic &O)
    {
        n=(n*O.n)%m;
        return *this;
    }
 
    auto inv() const
    {
        if(assume_prime)
            return pow(*this,m-2);
        else return pinv();
    }
 
    auto& operator/=(const d_cyclic &O)
    {
        return (*this)*=O.inv();
    }
 
    auto operator*(const d_cyclic &O) const
    {
        auto w=*this;
        return w*=O;
    }
 
    auto operator+(const d_cyclic &O) const
    {
        auto w=*this;
        return w+=O;
    }
 
    d_cyclic operator-() const
    {
        return d_cyclic(m-n);
    }
 
    auto operator-(const d_cyclic &O) const
    {
        auto w=*this;
        return w-=O;
    }
 
    auto operator/(const d_cyclic &O) const
    {
        return (*this)*O.inv();
    }
 
    d_cyclic pinv() const
    {
        return egcd(n,m).a;
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
        d_cyclic r(n);
        *this += 1;
        return r;
    }
 
    auto operator--(int)
    {
        d_cyclic r(n);
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
 
inline auto operator*(int k,d_cyclic O)
{
    return O*=k;
}
 
template<>
struct std::hash<d_cyclic>
{
    inline static std::random_device dev=std::random_device();
    inline static std::mt19937_64 g=std::mt19937_64(dev());
    inline static constexpr integer M=1e9+7;
    std::uniform_int_distribution<integer> d=std::uniform_int_distribution<integer>(1,M);
    integer a=d(g),b=d(g);
public:
    auto operator()(const d_cyclic &x) const
    {
        return (a*static_cast<integer>(x)+b)%M;
    }
};
 
inline std::vector<integer> inverse_table(int n,int prime)
{
    std::vector<integer> I(n + 1);
    I[0] = I[1] = 1;
    for (int i = 2; i <= n; i++)
        I[i] = I[prime % i] *
               (prime - prime / i) % prime;
    return I;
}
 
inline integer primitive_root_of_unity(integer p,factoriser &F)
{
    d_cyclic::m=p;
    auto phi=F.totient(p);
    auto D=F.divisors_list(phi);
    for(integer k=2;k<p-1;k++)
    {
        bool is_primitive=true;
        for (auto d: D)
            if(d< phi && pow<d_cyclic>(k,d)==1)
            {
                is_primitive=false;
                break;
            }
        if(is_primitive)
            return k;
    }
    return 0;
}
 
template <integer p>
integer primitive_root_of_unity(factoriser& F)
{
    static auto phi = F.totient(p);
    static auto D = F.divisors_list(phi);
    for (integer k = 2; k < p - 1; k++)
    {
        bool is_primitive = true;
        for (auto d : D)
            if (d < phi && pow<d_cyclic>(k, d) == 1)
            {
                is_primitive = false;
                break;
            }
        if (is_primitive)
            return k;
    }
    return 0;
}
 
template<typename cyclic_field>
integer legendre_symbol(cyclic_field a)
{
    integer r= (integer)pow(a, (cyclic_field::m - 1) / 2);
    if (r > cyclic_field::m / 2)
        r -= cyclic_field::m;
    return r;
}
 
 
//
// Created by ASUS on 01/12/2021.
//
 
 
 
#include <numbers>
#include <algorithm>
#include <optional>
 
const real pi = acos(-1);
/*
 * Fast Fourier Transform over Complex numbers
 * Suitable for smooth numbers
 * */
template<bool is_inverse=false>
struct fast_fourier
{
    int n;
    std::complex<real> w;
    using IC=std::complex<real>;
    inline static constexpr int sign=is_inverse?1:-1;
    inline static std::optional<std::reference_wrapper<factoriser>> F_ref=std::optional<std::reference_wrapper<factoriser>>();
 
public:
    inline static bool use_normalized=false;
    fast_fourier(int _n):n(_n),w(std::exp(IC(0,2*sign*pi/n)))
    {
    }
    virtual std::vector<IC> unnormalized(const std::vector<IC> &X) const
    {
        if(n==1)
            return X;
        auto &F=F_ref.value().get();
        auto p=F.smallest_divisor(n),q=n/p;
        fast_fourier<is_inverse> FFT(q);
        std::vector<std::vector<IC>> U(p,std::vector<IC>(q));
        for(int i=0;i<n;i++)
            U[i%p][i/p]=X[i];
        std::vector<std::vector<IC>> V(p);
        for(int i=0;i<p;i++)
            V[i]=FFT.unnormalized(U[i]);
        std::vector<IC> R(n);
        IC z=std::pow(w,q);
        IC t=1;
        for(int i=0;i<p;i++,t*=z)
        {
            IC h1=1,h2=1;
            for (int j = 0; j < p; j++,h1*=t,h2*=w)
            {
                IC h3=1;
                for (int k = 0; k < q; k++,h3*=h2)
                    R[i*q+k] += h1 * h3 * V[j][k];
            }
        }
        return R;
    }
    std::vector<IC> operator()(const std::vector<IC> &X) const
    {
        return use_normalized? normalized(X):unnormalized(X);
    }
    std::vector<IC> normalized(const std::vector<IC>&X) const
    {
        auto Y= unnormalized(X);
        for(auto &y:Y)
            y/=std::sqrt(n);
        return Y;
    }
    static void set_factoriser(factoriser &F)
    {
        F_ref=F;
        fast_fourier<!is_inverse>::F_ref=F;
    }
 
    static factoriser& get_factoriser()
    {
        return F_ref.value();
    }
};
 
/*
 * Fast Fourier Transform over Complex numbers
 * Works only on power of two (optimized for this case)
 * */
 
constexpr integer M=998244353;
using IK=d_cyclic;
 
 
 
void inplace_fft2(std::vector<IK> & a, IK s, bool inverse = false) {
    int n = a.size();
 
    static std::map<integer,IK> inverse_cache;
    if(!inverse_cache.count(n))
        inverse_cache[n]=IK{n}.inv();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            std::swap(a[i], a[j]);
    }
    std::vector<IK> wLen{s};
    while(s!=1)
    {
        s*=s;
        wLen.push_back(s);
    }
    wLen.pop_back();
    std::reverse(wLen.begin(),wLen.end());
    for (int len = 2,k=0; len <= n; len <<= 1,k++)
    {
        IK wlen = wLen[k];
        for (int i = 0; i < n; i += len) {
            IK w(1);
            for (int j = 0; j < len / 2; j++) {
                auto u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    auto n_inv=inverse_cache[n];
    if (inverse) {
        for (auto & x : a)
            x *= n_inv;
    }
}
 
 
struct cyclic_polynomial
{
    inline static int degree=1;
    inline static IK w1,w2;
    std::vector<IK> v;
    cyclic_polynomial(IK k=0)
    {
        v.resize(degree<<1);
        v[0]=k;
    }
    cyclic_polynomial(const std::vector<IK> &_v):v(_v)
    {
        for(int i=degree;i<v.size();i++)
            v[i%degree]+=v[i];
        v.resize(degree<<1);
    }
    cyclic_polynomial(std::vector<IK> &&_v):v(std::move(_v))
    {
        for(int i=degree;i<v.size();i++)
            v[i%degree]+=v[i];
        v.resize(degree<<1);
    }
 
 
    cyclic_polynomial operator+(const cyclic_polynomial &P) const
    {
        std::vector<IK> R(degree);
        for(int i=0;i<degree;i++)
            R[i]=v[i]+P.v[i];
        return R;
    }
 
    cyclic_polynomial operator*(const cyclic_polynomial &P) const
    {
        auto a=v,b=P.v;
        inplace_fft2(a,w1,false);
        inplace_fft2(b,w1,false);
        for(int i=0;i<a.size();i++)
            a[i]*=b[i];
        inplace_fft2(a,w2,true);
        return a;
    }
 
 
    auto operator[](int i) const
    {
        return v[i];
    }
 
    static void set_root_of_unity(IK w)
    {
        w1=w;
        w2=w.inv();
        w1=pow(w1,(M-1)/(degree<<1));
        w2=pow(w2,(M-1)/(degree<<1));
    }
};
 
 
 
constexpr integer N=1e5;
int main()
{
 
    d_cyclic::m=M;
    int &k=cyclic_polynomial::degree,n;
    std::cin >> k >> n;
    k=1<<k;
    cyclic_polynomial A({0,1}),I(1);
    cyclic_polynomial::set_root_of_unity(3);
    integer m=0;
    auto R=I+A;
    R.v.resize(k);
    inplace_fft2(R.v,cyclic_polynomial::w1);
    for(auto &r:R.v)
        r=pow(r,n);
    inplace_fft2(R.v,cyclic_polynomial::w2,true);
    for(int i=0;i<k;i++)
        std::cout << static_cast<integer>(R[i]) << ' ';
}
