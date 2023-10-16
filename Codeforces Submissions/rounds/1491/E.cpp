#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;
const int N = 2e5+7;

bool fib[N] = {0};

vector<vector<int>> tree(N);
int level[N];
vector<int> nodes;
int pr[N];

void cut_edge(int a, int b) {
   for (int i = 0; i < tree[a].size(); i++) {
      if (tree[a][i] == b)
         swap(tree[a].back(), tree[a][i]);
   }
   tree[a].pop_back();
}

void dfs(int node, int par = -1) {
   nodes.push_back(node);
   level[node] = 1;
   pr[node] = par;
   for (int v : tree[node]) {
      if (par == v)
         continue;
      dfs(v, node);
      level[node] += level[v];
   }
}

bool solve(int node) {
   nodes.clear();
   dfs(node);
   if (nodes.size() <= 3)
      return true;
   if (!fib[(int)nodes.size()]) {
      return false;
   }
   for (int v : nodes) {
      int len = nodes.size();
      if (fib[level[v]] && fib[len-level[v]]) {
         int prr = pr[v];
         cut_edge(v,prr);
         cut_edge(prr,v);
         int a = level[v];
         return (solve(v) && solve(prr));
      }
   }
   return false;
}

int main() {
   SaveTime
   int a = 1, b = 1;
   while (a < N) {
      fib[a] = true;
      int y = a+b;
      a = b; b = y;
   }
   int n; cin >> n;
   for (int i = 0; i < n-1; i++) {
      int a,b; cin >> a >> b;
      tree[a].push_back(b);
      tree[b].push_back(a);
   }
   cout << (solve(1) ? "YES" : "NO");
}