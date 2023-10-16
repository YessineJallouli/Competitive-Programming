#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      string a,b; cin >> a >> b;
      int n = a.size();
      int m = b.size();
      int l = min(n,m);
      map<string, bool> mp;
      for (int i = 0; i < n; i++) {
         string s = "";
         for (int j = i; j < n; j++) {
            s+= a[j];
            mp[s] = true;
         }
      }
      int lMax = 0;
      for (int i = 0; i < m; i++) {
         string s = "";
         for (int j = i; j < m; j++) {
            s+= b[j];
            if (mp[s] && s.size() > lMax) {
               lMax = s.size();
            }
         }
      }
      cout << a.size() + b.size() - 2*lMax << endl;
      mp.clear();
   }
}