#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
vector<vector<int>> tree(N);

set<int> black;

int white[N];

int ans ;

void dfs(int node, int dist = 0, int par = -1) {
    if (dist >= ans)
        return;
    if (dist >= white[node])
        return;
    if (par != -1)
        white[node] = dist;
    for (int i : tree[node]) {
        if (i == par)
            continue;
        dfs(i, dist+1, node);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int c0;
        cin >> c0;
        int a[n];
        for (int i = 0; i < n - 1; i++) {
            cin >> a[i];
        }
        ans = n;

        for (int i = 0; i <= n; i++) {
            tree[i].clear();
            white[i] = n;
        }

        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        dfs(c0);
        for (int i = 0; i < n-1; i++) {
            ans = min(ans, white[a[i]]);
            cout << ans << ' ';
            dfs(a[i]);
        }
        cout << '\n';
    }
}