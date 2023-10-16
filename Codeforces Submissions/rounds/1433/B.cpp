#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      char s[n];
      for (int i = 0; i < n; i++)
         cin >> s[i];
      int d = -1, f;
      for (int i = 0; i < n; i++) {
         if (s[i] == '1') {
            d = i;
            break;
         }
      }
      if (d == -1) {
         cout << 0 << endl;
         continue;
      }
      for (int i = n-1; i >= 0; i--) {
         if (s[i] == '1') {
            f = i;
            break;
         }
      }
      int ans = 0;
      for (int i = d; i <= f; i++) {
         if (s[i] == '0')
            ans++;
      }
      cout << ans<< endl;

   }
}