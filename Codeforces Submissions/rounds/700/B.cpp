#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;
const int K = 20;
vector<vector<int>> tree(N);

int up[N][K];
int depth[N];
int tin[N];
int timer = 0;

void dfs(int node, int par = -1) {
    tin[node] = timer++;
    for (int ch : tree[node]) {
        if (ch == par)
            continue;
        else {
            depth[ch] = depth[node]+1;
            up[ch][0] = node;
            for (int i = 1; i < K; i++) {
                up[ch][i] = up[up[ch][i-1]][i-1];
            }
        }
        dfs(ch, node);
    }
}

int LCA(int a, int b) {
    if (depth[b] > depth[a])
        swap(a,b);
    int k = depth[a]-depth[b];
    for (int j = K-1; j >= 0; j--) {
        if (k & (1 << j))
            a = up[a][j];
    }
    if (a == b)
        return a;
    for (int j = K-1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}



int main() {
    int n,k; cin >> n >> k;
    vector<int> universities;
    for (int i = 0; i < 2*k; i++) {
        int u; cin >> u;
        universities.push_back(u);
    }
    for (int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    ll ans = 0;
    pair<int,int> dist[2*k];

    int root = universities[0];

    dfs(root);

    for (int i = 0; i < 2*k; i++) {
        int node = universities[i];
        dist[i] = {tin[node], node};
    }

    sort(dist, dist+2*k);

    for (int i = 0; i < k; i++) {
        int n1 = dist[i].second;
        int n2 = dist[i+k].second;
        int lca = LCA(n1, n2);
        ans+= depth[n1]+depth[n2]-2*depth[lca];
    }
    cout << ans;
}