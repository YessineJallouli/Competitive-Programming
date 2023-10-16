#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
   int n, m; cin >> n >> m;
   int x, y; cin >> x >> y;
   swap(x,y);
   cout << y << ' ' << x << endl;
   cout << 1 << ' ' << x << endl;
   cout << 1 << ' ' << 1 << endl;
   int grid[n+1][m+1];
   memset(grid, 0, sizeof grid);
   grid[y][x] = 1;
   grid[1][x] = 1;
   grid[1][1] = 1;
   bool N = false;
   for (int i = 1; i <= n; i++) {
      N = !N;
      for (int j = 1; j <= m; j++) {
         if (N){
            x = j; y = i;
         }
         else {
            x = m-j+1; y = i;
         }
         if (grid[y][x] == 1)
            continue;
         cout << y << ' ' << x << endl;
         grid[y][x] = 1;
      }
   }
}