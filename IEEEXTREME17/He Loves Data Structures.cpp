//100%
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 6e5+7;
const int LOG = 20;
int up[N][LOG];
int depth[N];
int phi[N];
bool visited[N];

vector<vector<int>> tree(N);

void dfs(int a) {
    if (visited[a])
        return;
    visited[a] = true;
    for (int b : tree[a]) {
        if (visited[b])
            continue;
        depth[b] = depth[a]+1;
        up[b][0] = a;
        for (int j = 1; j < LOG; j++)
            up[b][j] = up[up[b][j-1]][j-1];
        dfs(b);
    }
}

int LCA(int a, int b) {
    if (depth[b] > depth[a])
        swap(a,b);
    int k = depth[a]-depth[b];
    for (int j = LOG-1; j >= 0; j--) {
        if (k & (1 << j))
            a = up[a][j];
    }
    if (a == b)
        return a;
    for (int j = LOG-1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int dist(int a, int b) {
    int c = LCA(a,b);
    return depth[a]+depth[b]-2*depth[c];
}

int main() {
    SaveTime
    int n; cin >> n;
    for (int i = 0; i < N; i++) {
        phi[i] = i; depth[i] = 0;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) {
            phi[j] -= phi[i];
        }
    }

    for (int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    deque<tuple<int,int,int>> d;
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 2) {
            int ans = 0;
            int nd; cin >> nd;
            for (int i = 0; i < d.size(); i++) {
                auto [v,l,r] = d[i];
                if (LCA(v,nd) == v) {
                    int dst = dist(v,nd);
                    if (dst <= r-l) {
                        ans = phi[l+dst];
                        break;
                    }
                }
            }
            cout << ans << '\n';
        }
        else {
            int a,b,c; cin >> a >> b >> c;
            d.emplace_front(a,b,c);
        }
    }
}
