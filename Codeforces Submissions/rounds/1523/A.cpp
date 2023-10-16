#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace  std;

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n,m; cin >> n >> m;
      string s; cin >> s;
      bool b = false;
      for (int i = 0; i < n; i++) {
         if (s[i] == '1')
            b = true;
      }
      if (!b) {
         cout << s << endl;
         continue;
      }
      for (int i = 0; i < min(n,m); i++) {
         string ch = s;
         for (int j = 0; j < n; j++) {
            int nb = 0;
            if (ch[j] == '0') {
               if (j+1 != n) {
                  if (ch[j+1] == '1')
                     nb++;
               }
               if (j != 0) {
                  if (ch[j-1] == '1')
                     nb++;
               }
               if (nb == 1) {
                  s[j] = '1';
               }
            }
         }
      }
      cout << s << endl;
   }
}