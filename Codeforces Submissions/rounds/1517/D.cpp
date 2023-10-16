#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

const int mx = 501;
ll dp[mx][mx][20];
vector<pair<pair<int,int>, int>> adj[mx][mx];
int n,m,k;
ll bfs(int i, int j, int K) {
   if (dp[i][j][K] != -1)
      return dp[i][j][K];
   if (K == 0)
      return 0;
   ll ans = INT_MAX;
   for (auto s : adj[i][j]) {
      int ii = s.first.first;
      int jj = s.first.second;
      int x = s.second;
      ans = min(ans, x+bfs(ii,jj,K-1));
   }
   return dp[i][j][K] = ans;

}

int main()
{
   cin >> n >> m >> k;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m-1; j++) {
         int x; cin >> x;
         adj[i][j].push_back({{i, j+1}, x});
         adj[i][j+1].push_back({{i,j},x});
      }
   }
   for (int i = 0; i < n-1; i++) {
      for (int j = 0; j < m; j++) {
         int x; cin >> x;
         adj[i][j].push_back({{i+1, j}, x});
         adj[i+1][j].push_back({{i,j},x});
      }
   }
   memset(dp,-1, sizeof dp);
   for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         if (k%2)
            cout << -1 << ' ';
         else
            cout << bfs(i,j,k/2)*2 << ' ';
      }
      cout << endl;
   }
}