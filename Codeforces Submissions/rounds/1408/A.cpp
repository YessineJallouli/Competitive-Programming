#include <bits/stdc++.h>

using namespace std;

int main()
{
   int T; cin>> T;
   while (T--) {
      int n; cin >> n;
      vector<vector<int>> v(3);
      for (int i = 0; i < 3; i++)
         for (int j = 0; j < n; j++)
         {
         int x; cin >> x;
         v[i].push_back(x);
         }
      int pr = -1;
      int ans[n];
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < 3; j++) {
            if (v[j][i] != pr) {
               ans[i] = v[j][i];
               pr = ans[i];
               break;
            }
         }
      }
      if (ans[0] == ans[n-1]) {
         for (int i = 0; i < 3; i++) {
            if (ans[0] != v[i][n-1] && ans[n-2]!= v[i][n-1])
               ans[n-1] = v[i][n-1];
         }
      }
      if (ans[0] == ans[n-1]) {
         for (int i = 0; i < 3; i++) {
            if (ans[n-1] != v[i][0] && ans[1] != v[i][0])
               ans[0] = v[i][0];
         }
      }
      for (int i : ans)
         cout << i << ' ';
      cout << endl;
   }
}