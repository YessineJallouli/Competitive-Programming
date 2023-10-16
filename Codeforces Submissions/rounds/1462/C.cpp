#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int x; cin >> x;
      if (x < 10) {
         cout << x << endl;
         continue;
      }
      if (x > 45) {
         cout << -1 << endl;
         continue;
      }
      int i = 9;
      string ans = "";
      while (x != 0) {
         char c = '0'+i;
         ans= c + ans;
         x-= i;
         i--;
         if (x == 0) {
            break;
         }
         if (x < i) {
            char c = '0'+x;
            ans = c + ans;
            break;
         }
      }
      cout << ans << endl;

   }
}