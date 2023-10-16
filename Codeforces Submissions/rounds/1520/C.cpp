#include "bits/stdc++.h"
using namespace std;
// Hi

int main(){
   ios::sync_with_stdio(0);cin.tie(0);
   int tt;
   cin>>tt;
   while(tt--){
      int n; cin >> n;
      if (n == 2) {
         cout << -1 << endl;
         continue;
      }
      int grid[n][n];
      int ans = 1;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if ((i+j)%2 == 0) {
               grid[i][j] = ans;
               ans++;
            }
         }
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if ((i+j)%2) {
               grid[i][j] = ans;
               ans++;
            }
         }
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             cout << grid[i][j] << ' ';
         }
         cout << endl;
      }
   }

   return 0;
}