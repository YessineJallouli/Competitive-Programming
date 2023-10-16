#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 2e5+3;
int mod = 1e9+7;
ll fact[mx];

int main()
{
   int T; cin >> T;
   fact[0] = 1;
   for (ll i = 1; i < mx; i++) {
      fact[i] = (fact[i-1]*i)%mod;
   }
   while (T--) {
      int n; cin >> n;
      ll num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      sort(num, num+n);
      ll ans = num[1];
      for (int i = 1; i < n; i++) {
         ans&= num[i];
      }
      if (ans != num[0]) {
         cout << 0 << endl;
         continue;
      }
      ll nb = 0;
      for (int i = 0; i < n; i++)
         if (num[i] == num[0])
            nb++;
      ll ans1 = fact[n-2] * nb%mod * (nb-1)%mod;
      cout << ans1 << endl;
   }
}