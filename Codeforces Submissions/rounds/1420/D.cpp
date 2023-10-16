#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mod = 998244353;
const int N = 3e5+7;

long long fact[N];
long long invfact[N];

long long fast_pow(long long a, long long b) {
   long long ans = 1;
   while (b > 0) {
      if (b & 1)
         ans = (ans*a)%mod;
      a = (a*a)%mod;
      b/= 2;
   }
   return ans;
}

long long modinv(long long a) {
   return fast_pow(a, mod-2);
}

void precompute() {
   fact[0] = 1;
   for (int i = 1; i < N; i++)
      fact[i] = fact[i-1] * i % mod;
   for (int i = 0; i < N; i++)
      invfact[i] = modinv(fact[i]);
}

long long C(int n, int k) {
   if (k > n)
      return 0;
   return fact[n] * invfact[n-k] % mod * invfact[k] % mod;
}

int fenTree[2*N];

void upd(int x) {
    for (; x < 2*N; x+=(x&(-x)))
        fenTree[x]+= 1;
}

int get(int x) {
    int ans = 0;
    for (; x; x-=(x&(-x)))
        ans+= fenTree[x];
    return ans;
}

int main() {
   SaveTime
   precompute();
   int n,k; cin >> n >> k;
   vector<pair<int,int>> v;
   set<int> s;
   for (int i = 0; i < n; i++) {
       int a,b; cin >> a >> b;
       s.insert(a);
       s.insert(b);
       v.push_back({a,b});
   }
   map<int,int> m;
   int nb = 1;
   for (int i : s) {
       m[i] = nb++;
   }
   sort(v.begin(), v.end());
   ll ans = 0;
   for (int i = 0; i < n; i++) {
       auto [a,b] = v[i];
       a = m[a], b = m[b];
       int nb = get(2*N-2) - get(a-1);
       ans = (ans + C(nb, k-1))%mod;
       upd(b);
   }
   cout << ans;

}