#include <bits/stdc++.h>
#define ll long long
using namespace std;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    int n,m,s,k; cin >> n >> m >> s >> k;
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a,b,w; cin >> a >> b >> w;
        adj[a].emplace_back(b,w);
        adj[b].emplace_back(a,w);
    }
    bool visited[n+1][7];
    memset(visited, false, sizeof visited);

    int day = 1;
    bool ans = false;
    vector<pair<int,int>> v = {{s,day}};
    while (! v.empty()) {
        vector<pair<int,int>> aux;
        for (auto [a,b] : v) {
            if (a == k)
                ans = true;
            visited[a][b] = true;
        }
        if (ans) {
            break;
        }
        int nextDay = (day+1)%7;
        for (auto [node,d] : v) {
            if (! visited[node][nextDay]) {
                visited[node][nextDay] = true;
                aux.emplace_back(node, nextDay);
            }
            for (auto [ch, w] : adj[node]) {
                if (w%7 == day%7) {
                    if (visited[ch][nextDay])
                        continue;
                    visited[ch][nextDay] = true;
                    aux.emplace_back(ch,nextDay);
                }
            }
        }
        v.swap(aux);
        day++;
    }
    cout << day-1;
}