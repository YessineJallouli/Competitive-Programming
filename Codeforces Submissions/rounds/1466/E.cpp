#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int mod = 1e9+7;
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      ll x[n];
      int nb[61];
      memset(nb, 0, sizeof nb);
      for (int i = 0; i < n; i++) {
         cin >> x[i];
         for (int j = 0; j < 61; j++) {
            if (x[i] & (1LL << j)) {
               nb[j]++;
            }
         }
      }
      ll ans = 0;
      for (int i = 0; i < n; i++) {
         ll x1 = 0;
         ll x2 = 0;
         for (int j = 0; j < 61; j++) {
            if (x[i] & (1LL << j)) {
               x1 = (x1 + (n* ((1LL << j)%mod))%mod)%mod;
               x2 = (x2+ (nb[j]* ((1LL << j)%mod))%mod)%mod;
            }
            else
               x1 = (x1 + (nb[j]* ((1LL << j)%mod))%mod)%mod;
         }
         ans = (ans + (x1*x2)%mod)%mod;
      }
      cout << ans << '\n';
   }
}