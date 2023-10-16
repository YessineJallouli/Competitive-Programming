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
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int grid[n][5];
      for (int i = 0; i < n; i++)
         for (int j = 0; j < 5; j++)
            cin >> grid[i][j];
      int ans = 0;
      for (int i = 1; i < n; i++) {
         int nb = 0;
         for (int j = 0; j < 5; j++) {
            if (grid[i][j] > grid[ans][j])
               nb++;
         }
         if (nb < 3)
            ans = i;
      }
      for (int i = 0; i < n; i++) {
         if (i == ans)
            continue;
         int nb = 0;
         for (int j = 0; j < 5; j++) {
            if (grid[i][j] > grid[ans][j])
               nb++;
         }
         if (nb < 3) {
            ans = -2;
            break;
         }
      }
      cout << ans+1 << '\n';
   }
}