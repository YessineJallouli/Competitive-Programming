#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;
vector<vector<int>> tree(N);
set<int> notUsed;
int cnt[N];
int a[N];
int ans[N];

void dfs(int node, int par = -1) {
    int c = a[node];
    cnt[c]++;
    if (cnt[c] == 1) {
        notUsed.erase(c);
    }
    ans[node] = *notUsed.begin();
    for (int i : tree[node]) {
        if (i == par)
            continue;
        dfs(i, node);
    }
    cnt[c]--;
    if (cnt[c] == 0) {
        notUsed.insert(c);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        notUsed.clear();
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i <= n; i++) {
            cnt[i] = 0;
            tree[i].clear();
            notUsed.insert(i);
        }
        for (int i = 2; i <= n; i++) {
            int p; cin >> p;
            tree[p].push_back(i);
            tree[i].push_back(p);
        }
        dfs(1);
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}
