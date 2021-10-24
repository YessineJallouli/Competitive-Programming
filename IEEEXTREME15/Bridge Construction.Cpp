#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;

vector<vector<int>> tree(N);

int root;
int mx = 0;

int dist1, dist2;

int pr[N];

int k1,k2;

void dfs(int node, int par = -1, int dist = 0) {
    pr[node] = par;
    if (dist > mx) {
        mx = dist;
        root = node;
    }
    for (int i : tree[node]) {
        if (i == par)
            continue;
        dfs(i, node, dist+1);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        for (int i = 0; i < N; i++) {
            tree[i].clear();
        }
        int n1;
        cin >> n1;
        for (int i = 1; i < n1; i++) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        int n2; cin >> n2;
        for (int i = 1; i < n2; i++) {
            int a,b; cin >> a >> b;
            tree[a+n1].push_back(b+n1);
            tree[b+n1].push_back(a+n1);
        }
        mx = 0;
        dfs(1);
        mx = 0;
        dfs(root);
        dist1 = mx/2;
        k1 = root;
        while (mx != dist1) {
            k1 = pr[k1];
            mx--;
        }
        mx = 0;
        dfs(n1+1);
        mx = 0;
        dfs(root);
        dist2 = mx/2;
        k2 = root;
        while (mx != dist2) {
            k2 = pr[k2];
            mx--;
        }
        tree[k1].push_back(k2);
        tree[k2].push_back(k1);
        mx = 0;
        dfs(1);
        mx = 0;
        dfs(root);
        cout << mx << '\n';
        cout << k1 << ' ' << k2-n1 << '\n';
    }
}
