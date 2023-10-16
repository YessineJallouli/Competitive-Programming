#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


const int mx = 51;
ll pow2[mx];

int main() {
   SaveTime
   pow2[0] = 1;
   for (int i = 1; i < mx; ++i)
      pow2[i] = pow2[i-1]*2;
   int T; cin >> T;
   while (T--) {
      ll h,p; cin >> h >> p;
      ll nb = pow2[h]-1;
      ll ready = 1;
      ll ans = 0;
      while (nb > 0) {
         nb-= min(ready, p);
         ans++;
         if (ready < p)
            ready*= 2;
         else {
            ll res = nb/p;
            ans+= res;
            if (nb%p)
               ans++;
            break;
         }
      }
      cout << ans << '\n';
   }
}