#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const ll inf = 1e18;

const int N = 2e5+7;

vector<ll> d(N);
vector<int> p(N);
vector<vector<pair<int,int>>> graph(N);
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;

int main() {
   SaveTime
   d.assign(N, inf);
   p.assign(N, -1);

   int n,m; cin >> n >> m;
   for (int i = 0; i < m; i++) {
      int a,b,w; cin >> a >> b >> w;
      graph[a].push_back({b,w});
      graph[b].push_back({a,w});
   }

   d[1] = 0;
   q.push({0, 1});
   while (!q.empty()) {
      int v = q.top().second;
      q.pop();
      for (auto edge : graph[v]) {
         int node = edge.first;
         int w = edge.second;
         if (w + d[v] < d[node]) {
            d[node] = w + d[v];
            p[node] = v;
            q.push({d[node], node});
         }
      }
   }
   if (d[n] == inf) {
      cout << -1;
      return 0;
   }
   vector<int> ans;
   int id = n;
   while (id != -1) {
      ans.push_back(id);
      id = p[id];
   }
   reverse(ans.begin(), ans.end());
   for (int i : ans)
      cout << i << ' ';
}