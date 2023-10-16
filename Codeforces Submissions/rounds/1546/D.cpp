/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mod = 998244353;
const int mx = 1e5+7;

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
      int n; cin >> n;
      string s; cin >> s;
      int nb = 0;
      int pairs = 0;
      int zeros = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == '0') {
            pairs+= nb/2;
            zeros++; nb = 0;
         }
         else {
            nb++;
         }
      }
      pairs+= nb/2;
      cout << C(zeros+pairs, pairs) << endl;
   }
}