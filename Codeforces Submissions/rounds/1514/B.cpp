#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 1e9+7;

int main() {
   int T; cin >> T;
   while (T--) {
      ll n,k; cin >> n >> k;
      ll ans = 1;
      for (int i = 0; i < k; i++) {
         ans = (ans*n)%mod;
      }
      cout << ans << endl;
   }
}