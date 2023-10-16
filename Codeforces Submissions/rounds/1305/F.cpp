#include <bits/stdc++.h>
#define ll long long
using namespace std;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int n;

const int mx = 2e5+7;
ll num[mx];

ll nb(ll n, ll p) {
   if (n < p)
      return p-n;
   return min(n%p, p-n%p);
}

ll tryy(ll p) {
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      ans+= nb(num[i], p);
   }
   return ans;
}

ll tr(ll x) {
   ll X = x;
   ll ans = LLONG_MAX;
   for (ll i = 2; i*i <= x; i++) {
      bool b = false;
      while (X%i == 0) {
         b = true;
         X = X/i;
      }
      if (b) {
         ans = min(ans, tryy(i));
      }
   }
   if (X != 1) {
      ans = min(ans, tryy(X));
   }
   return ans;
}

int main()
{
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> num[i];
   ll ans = LLONG_MAX;
   for (int it = 0; it < 6; it++) {
      int i = mt()%n;
      ll x = num[i];
      if (x != 1)
         ans = min(tr(x),ans );
      if (x != 1)
         ans = min(ans, tr(x-1));
      ans = min(ans, tr(x+1));
   }
   cout << ans;
}