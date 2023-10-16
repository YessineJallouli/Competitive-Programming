#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace  std;

const int mx = 1e4+7;

map<int,bool> dp;

void dfs(int n) {
   if (dp[n])
      return;
   if (n > mx)
      return;
   dp[n] = true;
   dfs(n+11);
   dfs(n+111);
   dfs(n+1111);
   dfs(n+11111);
   dfs(n+111111);
   dfs(n+1111111);
   dfs(n+11111111);
   dfs(n+111111111);
}

int main() {
   dfs(0);
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      if (n < 10000) {
         if (dp[n])
            cout << "YES" << endl;
         else
            cout << "NO" << endl;
      }
      else
         cout << "YES" << endl;
   }
}