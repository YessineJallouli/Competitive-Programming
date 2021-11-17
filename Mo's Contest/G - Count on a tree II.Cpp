//https://www.spoj.com/problems/COT2/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct query {
    int L,R,id;
    query() {
        L = R = id = 0;
    }
    query(int _L, int _R, int _id) {
        L = _L;
        R = _R;
        id = _id;
    }
};

int block;

bool cmp(query q1, query q2) {
    if (q1.L/block < q2.L/block)
        return true;
    if (q1.L/block == q2.L/block && q1.R < q2.R)
        return true;
    return false;
}

const int N = 1e5+7;
const int LOG = 20;
vector<vector<int>> tree(N);
int color[N];
int depth[N];
int tin[N];
int tout[N];
int up[N][LOG];
vector<int> tim;
bool visited[N];
int occColor[N];


void dfs(int node,int par = -1) {
    tim.push_back(node);
    tin[node] = tim.size()-1;
    for (int ch : tree[node]) {
        if (ch == par)
            continue;
        depth[ch] = depth[node] + 1;
        up[ch][0] = node;
        for (int j = 1; j < LOG; j++) {
            up[ch][j] = up[up[ch][j-1]][j-1];
        }
        dfs(ch, node);
    }
    tim.push_back(node);
    tout[node] = tim.size()-1;
}

int lca(int a, int b) {
    if (depth[a] > depth[b])
        swap(a,b);
    int k = depth[b]-depth[a];
    for (int j = LOG-1; j >= 0; j--) {
        if (k & (1<<j))
            b = up[b][j];
    }

    if (a == b)
        return b;
    for (int j = LOG-1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int nb = 0;

void ins(int node) {
    if (visited[node]) {
        visited[node] = false;
        occColor[color[node]]--;
        if (occColor[color[node]] == 0)
            nb--;
    }
    else {
        visited[node] = true;
        occColor[color[node]]++;
        if (occColor[color[node]] == 1)
            nb++;
    }
}

void del(int node) {
    if (visited[node]) {
        visited[node] = false;
        occColor[color[node]]--;
        if (occColor[color[node]] == 0)
            nb--;
    }
    else {
        visited[node] = true;
        occColor[color[node]]++;
        if (occColor[color[node]] == 1)
            nb++;
    }
}

int main() {
    int n,q; scanf("%d%d", &n,&q);
    block = sqrt(n);
    set<int> s;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
        s.insert(color[i]);
    }
    int H = 1;
    map<int,int> m;
    for (int i : s) {
        m[i] = H++;
    }
    for (int i = 1; i <= n; i++) {
        color[i] = m[color[i]];
    }
    for (int i = 0; i < n-1; i++) {
        int a,b; scanf("%d%d", &a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    depth[1] = 0;
    for (int i = 0; i < LOG; i++) {
        up[1][i] = 1;
    }
    dfs(1);
    query qr[q];
    for (int i = 0; i < q; i++) {
        int a,b; scanf("%d%d", &a,&b);
        int l = lca(a,b);
        if (tin[a] < tin[b])
            swap(a,b);
        if (l == b) {
            qr[i] = query(tin[b], tin[a], i);
            // HH
        }
        else {
            qr[i] = query(tout[b], tin[a], i);
        }
    }
    sort(qr, qr+q, cmp);
    int ans[q];
    memset(ans, false,sizeof ans);
    int l = 0, r = -1;
    for (int i = 0; i < q; i++) {
        auto [L,R,id] = qr[i];
        while (r < R) {
            r++;
            ins(tim[r]);
        }
        while (r > R) {
            del(tim[r]);
            r--;
        }
        while (l < L) {
            del(tim[l]);
            l++;
        }
        while (l > L) {
            l--;
            ins(tim[l]);
        }
        int n1 = tim[L], n2 = tim[R];
        int l = lca(n1, n2);
        ans[id] = nb;
        if (occColor[color[l]] == 0)
            ans[id]++;

    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
}
