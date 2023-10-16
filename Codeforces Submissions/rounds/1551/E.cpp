/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 2e3+7;
int num[mx];
int n;
int dp[mx][mx];

int solve(int id, int nbRem) {
   if (nbRem < 0)
      return -2e9;
   if (id == -1) {
      if (nbRem == 0)
         return 0;
      else
         return -2e9;
   }
   if (dp[id][nbRem] != -1)
      return dp[id][nbRem];
   int nb = 0;
   if (id+1-nbRem == num[id]) {
      nb++;
   }
   int ans = max(solve(id-1, nbRem-1), nb + solve(id-1, nbRem));
   return dp[id][nbRem] = ans;

}

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int k; cin >> n >> k;
      for (int i = 0; i < n; i++)
         cin >> num[i];
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++)
            dp[i][j] = -1;
      }
      int ans = -1;
      for (int i = n; i >= 0; i--) {
         int nb = solve(n-1, i);
         if (nb >= k)
            ans = i;
      }
      cout << ans << '\n';
   }
}