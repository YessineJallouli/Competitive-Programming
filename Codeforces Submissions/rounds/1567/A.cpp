#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      string ans = "";
      for (int i = 0; i < n; i++) {
         if (s[i] == 'U') {
            ans+= 'D';
         }
         else if (s[i] == 'D')
            ans+= 'U';
         else
            ans+= s[i];
      }
      cout << ans << '\n';
   }
}