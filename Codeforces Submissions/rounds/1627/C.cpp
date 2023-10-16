#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;
vector<vector<int>> tree(N);
map<pair<int,int>, int> id;
int res[N];

int root = -1;
int mx = 0;


void dfs1(int node, int par, int dist) {
    if (dist > mx) {
        mx = dist;
        root = node;
    }
    for (int i : tree[node]) {
        if (i == par)
            continue;
        dfs1(i, node, dist+1);
    }
}

void dfs(int node, int par, int cl) {
    if (par != -1) {
        int d = id[{node, par}];
        res[d] = cl;
    }
    for (int i : tree[node]) {
        if (i == par)
            continue;
        dfs(i, node, cl^1);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        root = -1;
        mx = 0;
        id.clear();
        int n; cin >> n;
        for (int i = 0; i <= n; i++)
            tree[i].clear();
        for (int i = 0; i < n-1; i++) {
            int a,b; cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
            id[{a,b}] = i;
            id[{b,a}] = i;
        }
        bool ans = true;
        for (int i = 1; i <=n; i++) {
            if (tree[i].size() >= 3)
                ans = false;
        }
        if (ans) {
            dfs1(1,-1, 0);
            dfs(root, -1, 0);
            for (int i = 0; i < n-1; i++) {
                if (res[i])
                   cout << 2 << ' ';
                else
                    cout << 3 << ' ';
            }
            cout << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}