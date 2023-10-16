#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 2e5+7;
int mod = 1e9+7;

ll dp[10][mx];

ll len(int n, int c) {
   if (dp[c][n] != -1) {
      return dp[c][n];
   }
   if (n+c < 10) {
      dp[c][n] = 1;
      return dp[c][n];
   }
   return dp[c][n] = (len(n-10+c,0)%mod + len(n-10+c,1)) % mod;

}
int main()
{
   ios_base::sync_with_stdio(false);
   int T; cin >> T;
   memset(dp,-1, sizeof dp);
   for (int i = 9; i >= 0; i--) {
      for (int n = mx-1; n >= 0; n--) {
         len(n,i);
      }
   }
   while (T--) {
      int n; int k; cin >> n >> k;
      ll ans = 0;
      while (n != 0) {
         ans= (ans + dp[n%10][k])%mod;
         n/=10;
      }
      cout << ans << '\n';
   }
}