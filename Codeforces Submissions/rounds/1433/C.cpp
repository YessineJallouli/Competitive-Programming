#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      int mx = 0;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         mx = max(mx, num[i]);
      }
      int k = num[0];
      bool b = true;
      for (int i = 0; i < n; i++) {
         if (num[i] != k)
            b = false;
      }
      if (b) {
         cout << -1 << endl;
         continue;
      }
      int ans = 0;
      //cout << mx << endl;
      for (int i = 0; i < n; i++) {
         if (num[i] == mx) {
            if (i != 0 && num[i-1] != mx)
               ans = i+1;
            if (i != n-1 && num[i+1] != mx)
               ans = i+1;
         }
      }
      cout << ans << endl;
   }
}