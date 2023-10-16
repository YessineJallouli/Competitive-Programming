#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      int odd, even; odd = even = 0;
      for (int i = 0; i < s.size(); i++) {
         if (i%2) {
            odd = odd*10 + s[i]-'0';
         }
         else {
            even = even*10 + s[i]-'0';
         }
      }
      cout << (odd+1)*(even+1)-2 << '\n';
   }
}