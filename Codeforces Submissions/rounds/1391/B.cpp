#include <bits/stdc++.h>

using namespace std;

int main() {

   int T; cin >> T;
   while (T--) {
      int n, m;
      cin >> n >> m;
      int grid[n][m];
      for (int i = 0; i < n; i++) {
         string s; cin >> s;
         for (int j = 0; j < m; j++)
            grid[i][j] = s[j];
      }
      int nb = 0;
      for (int i = 0; i < n-1; i++) {
         if (grid[i][m-1] != 'D')
            nb++;
      }
      for (int i = 0; i < m-1; i++) {
         if (grid[n-1][i] != 'R')
            nb++;
      }
      cout << nb << '\n';
   }
}