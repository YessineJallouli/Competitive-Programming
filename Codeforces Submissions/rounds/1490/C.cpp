#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

bool iscubic(ll n) {
   if (n < 1)
   return false;
   ll h = pow(n, 1.0/3.0);
   if (h*h*h == n)
      return true;
   h++;
   if (h*h*h == n)
      return true;
   return false;
}

int main() {
   int T; cin >> T;
   while (T--) {
      bool b = false;
      ll x; cin >> x;
      for (ll i = 1; i < 10000; i++) {
         ll a = i*i*i;
         if (x-a < 1)
            break;
         if (iscubic(x-a)) {
            b = true;
         }
      }
      if (b) {
         cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;
   }
}