#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int N = 2e5+7;
vector<vector<pair<int,int>>> adj(N);

bool visite[N];

ll d[N];
bool ans = true;


void dfs(int node, ll dist = 0) {
    if (d[node] == -1)
        d[node] = dist;
    else {
        visite[node] = true;
        if (d[node] != dist)
            ans = false;
        return;
    }
    visite[node] = true;
    for (auto [ch, w] : adj[node]) {
        dfs(ch, dist+w);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            visite[i] = false;
            d[i] = -1;
        }
        vector<tuple<int,int,int>> z;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].emplace_back(b,c);
            adj[b].emplace_back(a,-c);
        }
        ans = true;
        for (int i = 1; i <= n; i++) {
            if (visite[i])
                continue;
            dfs(i);
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}