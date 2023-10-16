#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;
vector<pair<int,int>> adj[N];
int dist[N];
int inf = 1e9+7;

int n,L,K;

int main() {
    freopen("path.in", "r", stdin);
    SaveTime
    int T; cin >> T;
    while (T--) {
        int m,s; cin >> n >> m >> s >> L >> K;
        for (int i = 0; i <= n; i++) {
            dist[i] = inf;
            adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int a,b,w; cin >> a >> b >> w;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        int ans = 0;
        while (! q.empty()) {
            int node = q.front();
            q.pop();
            for (auto [ch, w] : adj[node]) {
                if (dist[node] + 1 < dist[ch]) {
                    q.push(ch);
                    dist[ch] = dist[node] + 1;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (auto [ch, w] : adj[i]) {
                if (dist[i] < K)
                    ans = max(ans, w);
            }
        }
        cout << ans << '\n';
    }
}