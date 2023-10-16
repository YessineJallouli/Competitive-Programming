#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;
const int mx = 2e5+7;

long long fact[mx];
long long invfact[mx];

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
   for (int i = 1; i < mx; i++)
      fact[i] = fact[i-1] * i % mod;
   for (int i = 0; i < mx; i++)
      invfact[i] = modinv(fact[i]);
}

long long C(int n, int k) {
   if (k > n)
      return 0;
   return fact[n] * invfact[n-k] % mod * invfact[k] % mod;
}

int main() {
   SaveTime
   precompute();
   int T; cin >> T;
   while (T--) {
      ll n, k; cin >> n >> k;
      ll ans = 1;
      ll sum = 0;
      for (int i = 0; i < n; i+= 2) {
         sum = (sum + C(n,i))%mod;
      }
      if (n%2 == 0) {
         ll pw[k];
         for (int i = 0; i < k; i++) {
            ans = (ans*sum)%mod;
            pw[i] = ans;
         }
         for (int i = 0; i < k; i++) {
            if (i != 0) {
               ans = (ans + (pw[i-1] * fast_pow(2LL, (k-i-1)*n*1LL)))%mod;
            }
            else
               ans = (ans + fast_pow(2LL, (k-i-1)*n*1LL))%mod;
         }
      }
      else {
         sum = (sum+1)%mod;
         for (int i = 0; i < k; i++) {
            ans = (ans*sum)%mod;
         }
      }
      cout << ans << '\n';
   }
}