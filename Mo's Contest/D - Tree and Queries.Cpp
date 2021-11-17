//https://codeforces.com/problemset/problem/375/D
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct query {
    int L,R,k,id;
    query() {
        L = R = k = id = 0;
    }
    query(int _L, int _R, int _k, int _id) {
        L = _L;
        R = _R;
        k = _k;
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
int color[N];
vector<vector<int>> tree(N);
int tin[N];
int tout[N];
int occ[N];
int occColor[N];
int fenTree[N];

void upd(int x,int val) {
    if (x == 0)
        return;
    for (; x < N; x+= x&(-x))
        fenTree[x]+= val;
}

int get(int x) {
    int res = 0;
    for (; x; x-=x&(-x))
        res+= fenTree[x];
    return res;
}

vector<int> t_nodes;

void dfs(int node, int par = -1) {
    t_nodes.push_back(node);
    tin[node] = t_nodes.size()-1;
    for (int ch : tree[node]) {
        if (ch != par) {
            dfs(ch, node);
        }
    }
    t_nodes.push_back(node);
    tout[node] = t_nodes.size()-1;
}

void ins(int id) {
    if (occ[t_nodes[id]] == 1)
        return;
    occ[t_nodes[id]]++;
    upd(occColor[color[t_nodes[id]]], -1);
    occColor[color[t_nodes[id]]]++;
    upd(occColor[color[t_nodes[id]]], 1);
}

void del(int id) {
    if (occ[t_nodes[id]] == 0)
        return;
    occ[t_nodes[id]]--;
    upd(occColor[color[t_nodes[id]]], -1);
    occColor[color[t_nodes[id]]]--;
    upd(occColor[color[t_nodes[id]]], 1);
}

int main() {
    int n,q; scanf("%d%d", &n,&q);
    block = 2*n/sqrt(q)+1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
    }
    for (int i = 0; i < n-1; i++) {
        int a,b; scanf("%d%d", &a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    query qr[q];
    for (int i = 0; i < q; i++) {
        int nd, k; scanf("%d%d", &nd, &k);
        qr[i] = query(tin[nd], tout[nd], k, i);
    }
    sort(qr, qr+q, cmp);
    memset(occ, 0, sizeof occ);
    memset(occColor, 0, sizeof occColor);
    int ans[q];
    int l = 0, r = -1;
    for (int i = 0; i < q; i++) {
        auto [L,R,k,id] = qr[i];
        while (r < R) {
            r++;
            ins(r);
        }
        while (r > R) {
            del(r);
            r--;
        }
        while (l < L) {
            del(l);
            l++;
        }
        while (l > L) {
            l--;
            ins(l);
        }
        int nb = get(N-1) - get(k-1);
        ans[id] = nb;
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
}
