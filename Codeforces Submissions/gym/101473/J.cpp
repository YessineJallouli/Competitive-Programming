#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


const int N = 2e4+7;
const int LOG = 20;
int par[N], depth[N];
vector<vector<pair<int,int>>> MST(N);
int up[N][LOG];
int mn[N][LOG];

int Find(int node) {
   if (par[node] == node)
      return node;
   return par[node] = Find(par[node]);
}

bool Union(int n1, int n2) {
   int a1 = Find(n1);
   int a2 = Find(n2);
   if (a1 == a2)
      return true;
   par[a1] = a2;
   return false;
}

int dfs(int node, int pr = -1) {
   for (auto ch : MST[node]) {
      int v = ch.first;
      int w = ch.second;
      if (pr == v)
         continue;
      depth[v] = depth[node] + 1;
      up[v][0] = node;
      mn[v][0] = w;
      for (int j = 1; j < LOG; j++) {
         up[v][j] = up[up[v][j-1]][j-1];
         mn[v][j] = min(mn[v][j-1], mn[up[v][j-1]][j-1]);
      }
      dfs(v, node);
   }
}

int lca(int a, int b) {
   if (depth[b] > depth[a])
      swap(a,b);
   int k = depth[a]-depth[b];
   int res = INT_MAX;
   for (int j = LOG-1; j >= 0; j--) {
      if (k & (1 << j)) {
         res = min(res, mn[a][j]);
         a = up[a][j];
      }
   }
   if (a == b)
      return res;
   for (int j = LOG-1; j >= 0; j--) {
      if (up[a][j] != up[b][j]) {
         res = min(res, mn[a][j]);
         res = min(res, mn[b][j]);
         a = up[a][j];
         b = up[b][j];
      }
   }
   return min({res, mn[a][0], mn[b][0]});
}

int main()
{
   SaveTime
   int n,m,q; cin >> n >> m >> q;
   for (int i = 1; i <= n; i++)
      par[i] = i;
   vector<tuple<int,int,int>> graph(m);
   for (int i = 0; i < m; i++) {
      int a,b,w; cin >> a >> b >> w;
      graph[i] = {w,a,b};
   }
   sort(graph.rbegin(), graph.rend());

   for (int i = 0; i < m; i++) {
      int a = get<1>(graph[i]), b = get<2>(graph[i]), w = get<0>(graph[i]);
      if (Union(a,b))
         continue;
      MST[a].push_back({b,w});
      MST[b].push_back({a,w});
   }
   /// LCA
   for (int i = 1; i <= n; i++) {
      for (int j = 0; j < LOG; j++) {
         mn[i][j] = INT_MAX;
         up[1][j] = 1;
      }
   }
   depth[1] = 0;
   dfs(1);
   while (q--) {
      int a,b;
      cin >> a >> b;
      cout << lca(a,b) << '\n';
   }
}