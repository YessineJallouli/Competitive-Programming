/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n,m; cin >> n >> m;
      int grid[n][m];
      memset(grid, 0, sizeof grid);
      if (n%2 == 1 && m%2 == 1) {
         for (int i = 0; i < m; i+= 2)
            grid[0][i] = 1;
         for (int i = 2; i < n; i+= 2)
            grid[i][0] = 1;
         for (int i = 0; i < m; i+= 2)
            grid[n-1][i] = 1;
         for (int i = 2; i < n; i+= 2)
            grid[i][m-1] = 1;
      }
      if (n%2 == 1 && m%2 == 0) {
         for (int i = 0; i < n; i+= 2)
            grid[i][0] = 1;
         for (int i = 0; i < n; i+= 2)
            grid[i][m-1] = 1;
         for (int i = 2; i < m-2; i+= 2)
            grid[0][i] = 1;
         for (int i = 2; i < m-2; i+= 2)
            grid[n-1][i] = 1;

      }
      else {
         for (int i = 2; i < n-2; i+= 2)
            grid[i][0] = 1;
         for (int i = 2; i < n-2; i+= 2)
            grid[i][m-1] = 1;
         for (int i = 0; i < m; i+= 2)
            grid[0][i] = 1;
         for (int i = 0; i < m; i+= 2)
            grid[n-1][i] = 1;
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            cout << grid[i][j];
         }
         cout << endl;
      }
   }
}