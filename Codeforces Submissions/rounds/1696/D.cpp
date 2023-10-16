#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct node {
    int mn; int mx; int idmn; int idmx;
    node() {
        mn = INT_MAX;
        mx = INT_MIN;
        idmn = -1;
        idmx = -1;
    }
    node(int _mn, int _mx, int _idmn, int _idmx) {
        mn = _mn;
        mx = _mx;
        idmn = _idmn;
        idmx = _idmx;
    }
};

const int N = 3e5+7;

node tree[4*N];

vector<vector<int>> graph(N);
int a[N];

node mrg(node x, node y) {
    node res;
    if (x.mx < y.mx) {
        res.idmx = y.idmx;
        res.mx = y.mx;
    }
    else {
        res.idmx = x.idmx;
        res.mx = x.mx;
    }
    if (x.mn < y.mn) {
        res.idmn = x.idmn;
        res.mn = x.mn;
    }
    else {
        res.idmn = y.idmn;
        res.mn = y.mn;
    }
    return res;
}

int n;

void build(int id = 0, int ns = 0, int ne = n-1) {
    if (ns == ne) {
        tree[id] = node(a[ns], a[ns], ns, ns);
        return;
    }
    int md = (ns+ne)/2;
    int l = 2*id+1;
    int r = 2*id+2;
    build(l, ns, md);
    build(r, md+1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

node query(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
    if (qs > qe)
        return node();
    if (qs > ne || qe < ns)
        return node();
    if (ns >= qs && ne <= qe)
        return tree[id];
    int md = (ns+ne)/2;
    int l = 2*id+1;
    int r = 2*id+2;
    node x = query(qs, qe, l, ns, md);
    node y = query(qs, qe, r, md+1, ne);
    return mrg(x,y);
}

void solve(int i, int j) {
//    cout << i << ' ' << j << '\n';
    if (j-i <= 1)
        return;

    node q = query(i,j);
    int idmx = q.idmx;
    node q1 = query(idmx, j);
    int idmn = q1.idmn;
    if (idmn-idmx > 1) {
        //cout << idmn << ' ' << idmx << '\n';
        graph[idmn].push_back(idmx);
        graph[idmx].push_back(idmn);
    }
    node q2 = query(i, idmx);
    idmn = q2.idmn;
    if (idmx-idmn > 1) {
        //cout << idmn << ' ' << idmx << '\n';
        graph[idmn].push_back(idmx);
        graph[idmx].push_back(idmn);
    }
    solve(i, idmx-1);
    solve(idmx+1, j);
}

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }
        for (int i = 0; i < n-1; i++) {
            graph[i].push_back(i+1);
            graph[i+1].push_back(i);
        }
        build();
        solve(0, n-1);
        int ans[n];
        ans[0] = 0;
        vector<int> v = {0};
        bool vis[n];
        memset(vis, false, sizeof vis);
        while (! v.empty()) {
            vector<int> v1;
            for (int i : v) {
                for (int j : graph[i]) {
                    if (vis[j])
                        continue;
                    vis[j] = true;
                    ans[j] = ans[i]+1;
                    v1.push_back(j);
                }
            }
            v1.swap(v);
        }
        cout << ans[n-1] << '\n';
    }
}