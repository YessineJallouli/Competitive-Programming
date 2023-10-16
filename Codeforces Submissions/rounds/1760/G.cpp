#include <bits/stdc++.h>
using namespace std;

vector<int> path;

const int N = 1e5+7;
vector<vector<pair<int,int>>> tree(N);

int v1[N];
int v2[N];

int B;

void dfs(int node, bool b, int xw = 0,int par = -1) {
    if (b)
        v1[node] = xw;

    else {
        v2[node] = xw;
    }

    if (! b && node == B)
        return;

    for (auto [ch,w] : tree[node]) {
        if (ch == par) continue;
        dfs(ch, b, xw^w, node);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n,a,b; cin >> n >> a >> b;
        B = b;
        
        for (int i = 0; i <= n; i++) {
            tree[i].clear();
            v1[i] = v2[i] = -1;
        }
        for (int i = 0; i < n-1; i++) {
            int x,y,w; cin >> x >> y >> w;
            tree[x].push_back({y,w});
            tree[y].push_back({x,w});
        }
        dfs(a,false);
        dfs(b,true);
        bool ans = false;
        if (v2[b] == 0)
            ans = true;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            if (v2[i] == -1)
                continue;
            if (i == b || i == a)
                continue;
            if (v2[b] == v2[i])
                ans = true;
            s.insert(v2[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (i == a || i == b)
                continue;
            if (v1[i] == 0)
                ans = true;
            if (s.count(v1[i]))
                ans = true;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}