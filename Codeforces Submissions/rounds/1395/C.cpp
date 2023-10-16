#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
   int n, m; cin >> n >> m;
   int a[n], b[m];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   for (int i = 0; i < m; i++)
      cin >> b[i];
   vector<vector<int>> v(n);
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
         v[i].push_back(b[j]);
   }
   int ans = 0;
   for (int k = 9; k >= 0; k--) {
      vector<vector<int>> v1(n);
      bool fd = false;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < v[i].size(); j++) {
            int h1 = v[i][j];
            int s = a[i]&h1;
            int h = s >> k;
            int l = h&1;
            if (l == 0)
               v1[i].push_back(v[i][j]);
         }
         if (v1[i].size() == 0) {
            fd = true;
         }
      }
      if (!fd) {
         for (int m1 = 0; m1 < n; m1++) {
            v[m1].clear();
            for (int j = 0; j < v1[m1].size(); j++)
               v[m1].push_back(v1[m1][j]);
         }
      }
      else {
         ans+= 1 << k;
      }
   }
   cout << ans;
}