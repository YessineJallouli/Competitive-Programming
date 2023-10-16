#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 2e5+7;
vector<vector<int>> tree(N);
int color[N];

void dfs(int node, int par = -1) {
    if (par == -1)
        color[node] = 0;
    else
        color[node] = color[par]^1;
    for (int ch : tree[node]) {
        if (ch == par)
            continue;
        dfs(ch, node);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            tree[i].clear();
        }
        for (int i = 0; i < n-1; i++) {
            int a,b; cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        dfs(1);
        int nb = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0)
                nb++;
        }
        vector<int> z;
        if (nb > n/2) {
            for (int i = 1; i <= n; i++) {
                color[i]^= 1;
            }
            nb = n-nb;
        }
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0)
                z.push_back(i);
        }
        int ans[n+1];
        memset(ans, -1, sizeof ans);
        bool used[n+1];
        memset(used, 0, sizeof used);
        int id = 0;
        for (int i = 0; i < 20; i++) {
            if (nb & (1<<i)) {
                int x = (1 << i);
                int d = x;
                while (d < 2*x) {
                    ans[z[id++]] = d;
                    used[d] = true;
                    d++;
                }
            }
        }
        int d = 1;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == -1) {
                while (used[d])
                    d++;
                ans[i] = d++;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
}