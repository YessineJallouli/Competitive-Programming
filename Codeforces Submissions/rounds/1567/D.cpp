#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

vector<int> v;

ll pow10[15];

void solve(ll s, ll n) {
   if (n == 1) {
      v.push_back(s);
      return;
   }
   string ch = to_string(s);
   int len = ch.size()-1;
   int t = pow10[len];
   if (s-t >= n-1) {
      v.push_back(t);
      solve(s-t, n-1);
   }
   else {
      while (s-t < n-1) {
         t/= 10;
      }
      v.push_back(t);
      solve(s-t, n-1);
   }
}

int main() {
  // SaveTime
   pow10[0] = 1;
   for (int i = 1; i < 15; i++) {
      pow10[i] = pow10[i-1]*10;
   }
   int T; cin >> T;
   while (T--) {
      v.clear();
      ll s, n; cin >> s >> n;
      solve(s,n);
      for (int i : v)
         cout << i << ' ';
      cout << '\n';
   }
}