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
   SaveTime
   ll T; cin >> T;
   while (T--) {
      ll n, k; cin >> n >> k;
      ll maxGain = n*k;
      ll num[n];
      for (ll i = 0; i< n; i++) {
         cin >> num[i];
      }
      ll ans = LLONG_MIN;
      for (ll i = n; i > 0; i--) {
         for (ll j = i-1; j > 0; j--) {
            ll nb1 = num[i-1];
            ll nb2 = num[j-1];
            if (i*(i-1) - n*k >= i*j)
               break;
            ans = max(ans, i*j - k * (nb1|nb2));
         }
      }
      cout << ans << '\n';
   }
}