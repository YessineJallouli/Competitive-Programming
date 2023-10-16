#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      int n, m;
      cin >> n >> m;
      int grid[n][m];
      memset(grid, 0, sizeof grid);
      int row[n];
      int column[m];
      memset(row, 0, sizeof row);
      memset(column, 0, sizeof column);
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
               row[i] = column[j] = 1;
         }
      }
      bool first = false;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            if (row[i] == 0 && column[j] == 0) {
               first = ! first;
               row[i] = column[j] = 1;
            }
         }
      }
      if (first)
         cout << "Ashish" << '\n';
      else
         cout << "Vivek" << '\n';
   }
}