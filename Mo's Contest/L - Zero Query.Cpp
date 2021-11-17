//https://www.spoj.com/problems/ZQUERY/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct query {
    int L,R,T,id;
    query() {
        L = R = T = id = 0;
    }
    query(int _L, int _R, int _id) {
        L = _L;
        R = _R;
        id = _id;
    }
};

int block;

bool cmp(query &q1, query &q2) {
    return ((q1.L/block < q2.L/block) || (q1.L/block == q2.L/block && q1.R < q2.R));
}

const int N = 5e4+7;
int a[N];
int cum[N];
int tree[4*N];
int nb = 0;

deque<int> lastOcc[N];

int mrg(int x, int y) {
    return max(x,y);
}

int get(int qs, int qe, int id = 0, int ns = 0, int ne = N-1) {
    if (ns > qe || ne < qs) {
        return 0; // 0 for sum/gcd/or/xor and 1 for and/product and infinity for max/min
    }
    if (qs <= ns && qe >= ne) {
        return tree[id];
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

void upd(int pos, int val, int id = 0, int ns = 0, int ne = N-1) {
    if (pos > ne || pos < ns)
        return;
    if (ns == ne) {
        tree[id] = val;
        return;
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    upd(pos, val, l, ns, md);
    upd(pos, val ,r, md+1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

void ins(int id, char c) {
    if (c == 'R')
        lastOcc[cum[id]].push_back(id);
    else
        lastOcc[cum[id]].push_front(id);
    if (lastOcc[cum[id]].size() > 1) {
        upd(cum[id], lastOcc[cum[id]].back()-lastOcc[cum[id]][0]);
    }
}

void del(int id, char c) {
    if (c == 'R')
        lastOcc[cum[id]].pop_back();
    else
        lastOcc[cum[id]].pop_front();
    if (lastOcc[cum[id]].size() < 2) {
        upd(cum[id], 0);
    }
    else {
        upd(cum[id], lastOcc[cum[id]].back()-lastOcc[cum[id]][0]);
    }
}

int main() {
    SaveTime
    int n,q; cin >> n >> q;
    block = 600;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cum[0] = 0;
    int minCum = 0;
    for (int i = 0; i < n; i++) {
        cum[i+1] = cum[i]+a[i];
        minCum = min(minCum, cum[i+1]);
    }
    for (int i = 0; i <= n; i++) {
        cum[i]-= minCum;
    }
    query qr[q];
    for (int i = 0; i < q; i++) {
        int L,R; cin >> L >> R;
        qr[i] = query(L,R,i);
    }
    sort(qr, qr+q, cmp);
    int l = 0, r = -1;
    int ans[q];
    for (int i = 0; i < q; i++) {
        int L = qr[i].L, R = qr[i].R, id = qr[i].id;
        L--;
        while (r < R) {
            r++;
            ins(r, 'R');
        }
        while (l > L) {
            l--;
            ins(l, 'L');
        }
        while (r > R) {
            del(r, 'R');
            r--;
        }
        while (l < L) {
            del(l, 'L');
            l++;
        }
        nb = get(0,N-1);
        ans[id] = nb;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}
