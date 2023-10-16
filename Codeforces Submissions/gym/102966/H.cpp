#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9+7;

ll pow(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

ll modpow(ll x) {
   return pow(x, mod-2);
}

const int mx = 3e5+1;
ll fact[mx];

int main(){
   fact[0] = 1;
   for (int i = 1; i <= mx; i++)
      fact[i] = (fact[i-1]*i)%mod;
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      ll ans = (N*fact[2*N-1])%mod;
      ans = ans * modpow(fact[N])%mod;
      ans = ans * modpow(fact[N])%mod;
      cout << ans << endl;
   }
}