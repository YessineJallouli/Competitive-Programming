#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      ll n; cin >> n;
      ll ans = (n*(n+1))/2;
      //cout << ans << endl;
      for (ll i = 1; i <= n; i= i*2) {
         ans= ans - 2*i;
      }
      cout << ans << endl;
   }
}