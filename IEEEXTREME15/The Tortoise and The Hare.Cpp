#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const ll inf = 1e18;

const int N = 300005;

vector<ll> d(N);
vector<int> p(N);
vector<vector<pair<int,int>>> graph(N);
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;

int main() {
    SaveTime
    d.assign(N, inf);
    p.assign(N, -1);

    int n,m; cin >> n >> m;
    int x,y; cin >> x >> y;
    for (int i = 0; i < m; i++) {
        int a,b,w; cin >> a >> b >> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    // Shortest path from 1 to n
    ll ans = 0;
    ll res = -1;
    for (int c = 1; c <= n; c++) {
        if (c == x || c == y)
            continue;
        d.assign(N, inf);
        p.assign(N, -1);
        q= decltype(q)();
        d[x] = 0;
        q.push({0, x});
        while (!q.empty()) {
            int v = q.top().second;
            q.pop();
            for (auto edge: graph[v]) {
                int node = edge.first;
                int w = edge.second;
                if (w + d[v] < d[node] && node != c) {
                    d[node] = w + d[v];
                    p[node] = v;
                    q.push({d[node], node});
                }
            }
        }
        if (d[y] > ans && d[y] != inf) {
            res = c;
            ans = d[y];
        }
    }
    cout << res;
}
