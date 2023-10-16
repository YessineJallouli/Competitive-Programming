#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 1e5+7;

vector<vector<pair<int,int>>> tree(mx);
bool no[mx];
int mark[mx];

int ans = 0;

void dfs1(int node, int par = -1, ll sum = 0) {
   if (sum > mark[node]) {
      no[node] = true;
      return;
   }
   for (auto v : tree[node]) {
      if (v.first == par)
         continue;
      dfs1(v.first, node, max(0LL,sum+v.second));
   }
}

void dfs2(int node, int par = -1) {
   if (no[node])
      return;
   ans++;
   for (auto v : tree[node]) {
      if (v.first == par)
         continue;
      dfs2(v.first, node);
   }
}

int main() {
   SaveTime
   int n; cin >> n;
   for (int i = 1; i <= n;i++) {
      cin >> mark[i];
   }
   for (int i = 1; i < n; i++) {
      int p, c; cin >> p >> c;
      tree[i+1].push_back({p,c});
      tree[p].push_back({i+1,c});
   }
   dfs1(1);
   dfs2(1);
   cout << n-ans;
}