#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mx = 5005;
int dp[mx][mx];
int mod = 1e9+7;

vector<int> zero,one;

int solve(int i, int j) {
   if (dp[i][j] != -1)
      return dp[i][j];
   if (i == one.size()) {
      return 0;
   }
   if (j == zero.size()) {
      return mod;
   }
   return dp[i][j]  = min((solve(i+1, j+1)+abs(one[i]-zero[j])), solve(i, j+1));
}

int main()
{
   memset(dp,-1, sizeof dp);
   int n; cin >> n;
   for (int i = 0; i < n; i++) {
      int x; cin >> x;
      if (x) {
         one.push_back(i);
      }
      else
         zero.push_back(i);
   }
   cout << solve(0,0) << endl;
}