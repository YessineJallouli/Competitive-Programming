#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;

int dp[N];
int a[N];
int pr[N];
int x;
vector<vector<int>> tree(N);

bool ans = false;

void dfs(int node, int par = -1) {
    dp[node] = a[node];
    pr[node] = par;
    for (int ch : tree[node]) {
        if (par == ch)
            continue;
        dfs(ch, node);
        dp[node]^= dp[ch];
    }
}

void cut_edge(int a, int b) {
    for (int i = 0; i < tree[a].size(); i++)  {
        if (tree[a][i] == b)
            swap(tree[a][i], tree[a].back());
    }
    for (int i = 0; i < tree[b].size(); i++) {
        if (tree[b][i] == a)
            swap(tree[b][i], tree[b].back());
    }
    tree[a].pop_back();
    tree[b].pop_back();
}

void dfs1(int node, int par = -1) {
    dp[node] = a[node];
    for (int ch : tree[node]) {
        if (par == ch)
            continue;
        dfs1(ch, node);
        dp[node]^= dp[ch];
    }
    if (dp[node] == x)
        ans = true;
}

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n,k;
        cin >> n >> k;
        x = 0;
        for (int i = 1; i <= n; i++) {
            tree[i].clear();
            cin >> a[i];
            x^= a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        if (x == 0) {
            cout << "YES\n";
            continue;
        }
        else if (k == 2) {
            cout << "NO\n";
            continue;
        }
        dfs(1);
        ans = false;
        for (int i = 2; i <= n; i++) {
            if (dp[i] == x && !ans) {
                cut_edge(i, pr[i]);
                dfs1(pr[i]);
                tree[i].push_back(pr[i]);
                tree[pr[i]].push_back(i);
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}