#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;
vector<vector<int>> adj(N);
set<int> visited[N];
int a[N];



int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x; cin >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<int> v;
    v.insert(1);
    visited[1].insert(x);
    while (! v.empty()) {
        set<int> aux;
        for (int node : v) {
            int mx = *visited[node].rbegin();
            for (int ch : adj[node]) {
                int t;
                if (a[node] >= mx)
                    t = mx/2;
                else
                    t = mx;
                if (visited[ch].count(t))
                    continue;
                visited[ch].insert(t);
                aux.insert(ch);
            }
        }
        v.swap(aux);
    }
    int ans = *visited[n].rbegin();
    if (a[n] >= ans) {
        ans/= 2;
    }
    cout << ans;
}