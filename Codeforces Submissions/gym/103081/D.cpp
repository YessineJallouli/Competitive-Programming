#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;
vector<vector<pair<int,int>>> graph(N);
int inf = 1e9;

int main(){
    SaveTime
    int n,m,mn,mx; cin >> n >> m >> mn >> mx;
    for (int i = 0; i < m; i++) {
        int a,b,w; cin >> a >> b >> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    int dist[n];
    for (int i = 0; i < n; i++) {
        dist[i] = inf;
    }
    dist[0] = 0;
    q.push({0,0});
    while (! q.empty()) {
        auto [node,d] = q.top();
        q.pop();
        for (auto [ch, w] : graph[node]) {
            if (dist[node] + w < dist[ch] || dist[ch] == inf) {
                dist[ch] = dist[node] + w;
                q.push({ch, w});
            }
        }
    }
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({dist[i], i});
    }
    sort(v.begin(), v.end());
    set<pair<int,int>> vis;
    int ans = 0;
    for (auto [d, node] : v) {
        for (auto[i,w] : graph[node]) {
            int x = i, y = node;
            if (x > node)
                swap(x,y);
            if (vis.count({x,y}))
                continue;
            vis.insert({x,y});
            if (dist[node]*2 < mx)
                ans++;
        }
    }
    cout << ans;
}