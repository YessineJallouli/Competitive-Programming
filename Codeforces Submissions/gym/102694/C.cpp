#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

const int mx = 300007;
const int LOG = 21;
vector<vector<int>> tree(mx);
int level[mx];
int LCA[mx][LOG+1];

int LG2(int n)
{
   int nb = 0;
   while (n/2) {
      n/= 2;
      nb++;
   }
   return nb;
}

void dfs(int node, int lvl, int par)
{
   level[node] = lvl;
   LCA[node][0] = par;
   for (int i : tree[node]) {
      if (i == par)
         continue;
      dfs(i, lvl+1, node);
   }
}

void init(int n)
{
   dfs(1, 0, -1);
   for (int i = 1; i < LOG; i++) {
      for (int j = 1; j <= n; j++) {
         if (LCA[j][i-1] != -1) {
            int par = LCA[j][i-1];
            LCA[j][i] = LCA[par][i-1];
         }
      }
   }
}

int getLCA(int a, int b)
{
   if (level[b] < level[a])
      swap(a,b);
   int diff = level[b]-level[a];
   while (diff > 0) {
      int lg = LG2(diff);
      b = LCA[b][lg];
      diff-= 1<<lg;
   }
   if (a == b) {
      return a;
   }
   for (int i = LOG; i >= 0; i--) {
      if (LCA[a][i] != -1 && LCA[b][i] != LCA[a][i]) {
         a = LCA[a][i], b = LCA[b][i];
      }
   }
   return LCA[a][0];
}

void parcours(int &a, int lca, int &c) {
   int diff = level[a]-level[lca];
   int ans = min(c, diff);
   c-= ans;
   while (ans > 0) {
      int lg = LG2(ans);
      a = LCA[a][lg];
      ans-= 1 << lg;
   }
}

int main()
{
   int n; cin >> n;
   for (int i = 0; i < n-1; i++) {
      int a,b; cin >> a >> b;
      tree[a].push_back(b); tree[b].push_back(a);
   }
   memset(LCA, -1, sizeof LCA);
   init(n);
   int q; cin >> q;
   while (q--) {
      int a, b, c; cin >> a >> b >> c;
      int lca = getLCA(a,b);
      parcours(a, lca, c);
      if (c == 0) {
         cout << a << '\n';
         continue;
      }
      int req = level[b]-level[lca]-c;
      parcours(b, lca, req);
      cout << b << endl;
   }
}