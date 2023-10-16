#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 2e5+2;
int tree[4*N], lazy[4*N];
bool marked[4*N];

int n;

//upd : add x to range[a..b]
//query : sum of [a..b]

int mrg(int a, int b) {
    return a+b;
}

void unlazy(int id, int ns, int ne) {
    if (marked[id] == 0)
        return;
    tree[id] = lazy[id]*(ne-ns+1);
    if (ns != ne) {
        int l = 2*id+1;
        int r = 2*id+2;
        lazy[l] = lazy[id];
        lazy[r] = lazy[id];
        marked[l] = marked[r] = 1;
    }
    marked[id] = 0;
    lazy[id] = 0;
}

void upd(int qs, int qe, int val, int id = 0, int ns = 0, int ne = n-1) {
    unlazy(id, ns,ne);
    if (ns > qe || ne < qs) {
        return;
    }
    if (ns >= qs && ne <= qe) {
        lazy[id] = val;
        marked[id] = 1;
        unlazy(id,ns,ne);
        return;
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    upd(qs, qe, val, l, ns, md);
    upd(qs, qe, val, r, md+1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

int get(int qs,int qe, int id = 0, int ns = 0, int ne = n-1) {
    unlazy(id, ns, ne);
    if (ns > qe || ne < qs) {
        return 0; //not necessary zero
    }
    if (ns >= qs && ne <= qe)
        return tree[id];
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

int main() {

    int T; cin >> T;
    while (T--) {
        int q; cin >> n >> q;
        for (int i = 0; i <= 4*n; i++) {
            tree[i] = lazy[i] = marked[i] = 0;
        }
        tuple<int,int,int> w[q];
        for (int i = 0; i < q; i++) {
            int x1,x2,y; cin >> x1 >> x2 >> y;
            w[i] = {y,x1,x2};
        }
        sort(w, w+q);
        for (int i = 0; i < q; i++) {
            auto [y,x1,x2] = w[i];
            if (get(x1,x2) != x2-x1+1) {
                upd(x1, x2, 1);
                upd(x1, x1, 0);
                upd(x2, x2, 0);
            }
            else {
                upd(x1, x2, 1);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans+= 1-get(i,i);
        }
        cout << ans << '\n';
    }
}