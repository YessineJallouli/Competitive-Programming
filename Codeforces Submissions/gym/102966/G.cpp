#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   ll L, G; cin >> L >> G;
   deque<pair<int,int>> Goombas(G);
   ll ans = 0;
   for (int i = 0; i < G; i++) {
      ll x, d; cin >> x >> d;
      if (d == 1) {
         ans = max(ans, L-x);
      }
      else
         ans = max(ans, x);
   }
   cout << ans;
}