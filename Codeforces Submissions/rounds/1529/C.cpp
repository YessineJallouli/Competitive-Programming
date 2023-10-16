#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace  std;

const int mx = 1e5+7;
bool visite[mx];
vector<vector<int>> tree(mx);
int range[mx][2];
ll dp[mx][2];

ll dfs(int node, int id) {
   if (dp[node][id] != -1)
      return dp[node][id];
   visite[node] = true;
   int prev = range[node][id];
   ll ans = 0;
   for (int i : tree[node]) {
      if (visite[i])
         continue;
      int a = range[i][0];
      int b = range[i][1];
      int x = abs(a-prev);
      int y = abs(b-prev);
      ans = ans+ max(x+dfs(i,0),y+dfs(i,1));
   }
   visite[node] = false;
   return dp[node][id] = ans;
}

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      memset(dp, -1, sizeof dp);
      int n; cin >> n;
      for (int i = 1; i <= n; i++) {
         cin >> range[i][0] >> range[i][1];
         tree[i].clear();
      }
      for (int i = 0; i < n-1; i++) {
         int a,b; cin >> a >> b;
         tree[a].push_back(b);
         tree[b].push_back(a);
      }
      memset(visite,false, sizeof visite);
      ll ans = dfs(1, 0);
      memset(visite,false, sizeof visite);
      ans = max(ans, dfs(1,1));
      cout << ans << '\n';
   }
}