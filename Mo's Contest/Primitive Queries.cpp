//https://www.codechef.com/problems/DISTNUM3
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct query {
    int L,R,t,id;
    query() {
        L = R = t = id = 0;
    }
    query(int _L, int _R, int _t, int _id) {
        L = _L;
        R = _R;
        t = _t;
        id = _id;
    }
};

int block;
const int N = 1e5+7;
const int LOG = 20;
const int Q = 1e5+7;
int depth[N];
int tin[N];
int tout[N];
int up[N][LOG];
vector<int> tim;
bool visited[N];
vector<vector<int>> tree(N);
int a[N];
int occ[4*N];
int nb = 0;
pair<int,int> after[Q];
pair<int,int> before[Q];

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

bool cmp(query q1, query q2) {
    if (q1.L/block < q2.L/block)
        return true;
    if (q1.L/block == q2.L/block && q1.R/block < q2.R/block)
        return true;
    if (q1.L/block == q2.L/block && q1.R/block == q2.R/block && q1.t < q2.t)
        return true;
    return false;
}

void change(int node) {
    if (visited[node]) {
        visited[node] = false;
        occ[a[node]]--;
        if (occ[a[node]] == 0)
            nb--;
    }
    else {
        visited[node] = true;
        occ[a[node]]++;
        if (occ[a[node]] == 1)
            nb++;
    }
}

int main() {
    SaveTime
    int n,q; cin >> n >> q;
    block = pow(n,2/3.0)+1;
    set<int> s;
    map<int,int> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i = 0; i < 20; i++) {
        up[1][i] = 1;
    }
    dfs(1);
    vector<query> qr;
    int tmp = 0;
    for (int i = 0; i < q; i++) {
        int v,x,y; cin >> v >> x >> y;
        if (v == 2) {
            tmp++;
            before[tmp] = {x,a[x]};
            after[tmp-1] = {x,y};
            a[x] = y;
            s.insert(y);
        }
        else {
            int l = lca(x,y);
            if (tin[x] < tin[y])
                swap(x,y);
            if (l == y) {
                qr.push_back(query(tin[y], tin[x], tmp, i));
            }
            else {
                qr.push_back(query(tout[y], tin[x], tmp, i));
            }
        }
    }
    int H = 1;
    for (int i : s) {
        m[i] = H++;
    }
    for (int i = 1; i <= tmp; i++) {
        before[i].second = m[before[i].second],
        after[i-1].second = m[after[i-1].second];
    }
    for (int i = 1; i <= n; i++) {
        a[i] = m[a[i]];
    }
    sort(qr.begin(), qr.end(), cmp);
    int ans[q];
    for (int i = 0; i < q; i++) {
        ans[i] = INT_MAX;
    }
    int l = 0, r = -1;
    for (int i = 0; i < qr.size(); i++) {
        int L = qr[i].L, R = qr[i].R, t = qr[i].t, id = qr[i].id;
        while (tmp > t) {
            int idx = before[tmp].first, val = before[tmp].second;
            if (visited[idx]) {
                change(idx);
                a[idx] = val;
                change(idx);
            }
            else {
                a[idx] = val;
            }
            tmp--;
        }
        while (tmp < t) {
            int idx = after[tmp].first, val = after[tmp].second;
            if (visited[idx]) {
                change(idx);
                a[idx] = val;
                change(idx);
            }
            else {
                a[idx] = val;
            }
            tmp++;
        }
        while (r < R) {
            r++;
            change(tim[r]);
        }
        while (r > R) {
            change(tim[r]);
            r--;
        }
        while (l < L) {
            change(tim[l]);
            l++;
        }
        while (l > L) {
            l--;
            change(tim[l]);
        }
        int n1 = tim[L], n2 = tim[R];
        int l = lca(n1, n2);
        ans[id] = nb;
        if (occ[a[l]] == 0)
            ans[id]++;
    }
    for (int i = 0; i < q; i++) {
        if (ans[i] == INT_MAX)
            continue;
        cout << ans[i] << '\n';
    }
}
