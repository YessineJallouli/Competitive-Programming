#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      ll n; cin >> n;
      if (n%2050 != 0) {
         cout << -1 << endl;
         continue;
      }
      n/= 2050;
      ll ans = 0;
      while (n) {
         ans +=n%10;
         n/=10;
      }
      cout << ans << endl;
   }
}