/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   ll T; cin >> T;
   while (T--) {
      ll n; cin >> n;
      ll a[n], b[n];
      for (ll i = 0; i < n; i++) {
         cin >> a[i];
      }
      for (ll i = 0; i < n; i++)
         cin >> b[i];
      sort(a, a+n);
      sort(b, b+n);
      ll nb = 1;
      ll sff[n], sfx[n];
      sff[0] = b[n-1];
      sfx[0] = a[n-1];
      for (ll i = n-2; i >= 0; i--) {
         sff[nb] = sff[nb-1]+b[i];
         sfx[nb] = sfx[nb-1]+a[i];
         nb++;
      }
      ll D = n-n/4-1;
      if (sff[D] <= sfx[D]) {
         cout << 0 << endl;
         continue;
      }
      ll N = n;
      ll ans = 0;
      while (true) {
         ans++;
         N++;
         ll d = N-N/4;
         ll s2 = sff[min(d-1, n-1)];
         ll nb1 = min(d-ans-1, n-1);
         ll s1 = sfx[nb1]+100*ans;
         if (s1 >= s2) {
            break;
         }
      }
      cout << ans << endl;
   }
}