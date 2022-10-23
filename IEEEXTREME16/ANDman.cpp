//100%
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;
int sz[N], heavy[N], depth[N], top[N], pos[N], par[N];
vector<vector<int>> tree(N);
vector<int> segment_ids;
int n;

ll segTree[4*N];

void dfs(int node, int pr = -1) {
    sz[node] = 1;
    int mx = 0;
    for (int ch : tree[node]) {
        if (ch == pr)
            continue;
        par[ch] = node;
        depth[ch] = depth[node] + 1;
        dfs(ch, node);
        sz[node]+= sz[ch];
        if (mx < sz[ch]) {
            mx = sz[ch];
            heavy[node] = ch;
        }
    }
}

void decompose(int node, int head, int pr = -1) {
    segment_ids.push_back(node);
    pos[node] = (int) segment_ids.size()-1;
    top[node] = head;
    if (heavy[node]) {
        decompose(heavy[node], head, node);
    }
    for (int ch : tree[node]) {
        if (ch == pr || ch == heavy[node])
            continue;
        decompose(ch, ch, node);
    }
}

int mod = 1e9+7;

ll mrg(ll x, ll y) {
    return (x*y)%mod;
}


ll get(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
    if (ns > qe || ne < qs) {
        return 1LL; // 0 for sum/gcd/or/xor and 1 for and/product and infinity for max/min
    }
    if (qs <= ns && qe >= ne) {
        return segTree[id];
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

void upd(int pos, ll val, int id = 0, int ns = 0, int ne = n-1) {
    if (pos > ne || pos < ns)
        return;
    if (ns == ne) {
        segTree[id] = val;
        return;
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    upd(pos, val, l, ns, md);
    upd(pos, val ,r, md+1, ne);
    segTree[id] = mrg(segTree[l], segTree[r]);
}


int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        segment_ids.clear();
        cin >> n;
        for (int i = 0; i <= n; i++) {
            tree[i].clear();
            heavy[i] = false;
            depth[i] = pos[i] = top[i] = sz[i] = par[i] = 0;
        }
        for (int i = 0; i < 4*n; i++) {
            segTree[i] = 1;
        }
        int w[n+1];
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }
        for (int i = 0; i < n-1; i++) {
            int a,b; cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        depth[1] = 0;
        par[1] = 1;
        dfs(1);
        decompose(1, 1);
        for (int i : segment_ids) {
            upd(pos[i], w[i]);
        }
        int q;
        cin >> q;
        while (q--) {
            int t,a, b;
            cin >> t >> a >> b;
            if (t == 2) {
                ll ans = 1;
                for (; top[a] != top[b]; b = par[top[b]]) {
                    if (depth[top[a]] > depth[top[b]])
                        swap(a, b);
                    ans = (ans * get(pos[top[b]], pos[b]))%mod;
                }
                if (depth[a] > depth[b])
                    swap(a, b);
                ans = (ans * get(pos[a], pos[b]))%mod;
                cout << ans << '\n';
            }
            else {
                upd(pos[a], b);
            }
        }
    }
}
