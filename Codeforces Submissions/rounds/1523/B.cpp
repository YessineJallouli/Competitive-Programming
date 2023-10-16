#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace  std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      int ans = 6*n/2;
      cout << ans << endl;
      for (int i = 1; i <= n; i+=2) {
         cout << 1 << ' ' << i << ' ' << i+1 << endl;
         cout << 1 << ' ' << i << ' ' << i+1 << endl;
         cout << 2 << ' ' << i << ' ' << i+1 << endl;
         cout << 1 << ' ' << i << ' ' << i+1 << endl;
         cout << 1 << ' ' << i << ' ' << i+1 << endl;
         cout << 2 << ' ' << i << ' ' << i+1 << endl;
      }
   }
}