
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 2e5+2; // n max
int m;
int a[N], tree[4*N];

int mrg(int x, int y) {
    return max(x,y);
}

void build(int id = 0, int ns = 0, int ne = m-1) {
    if (ns == ne) {
        tree[id] = a[ns];
        return;
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    build(l, ns, md);
    build(r, md+1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

ll get(int qs, int qe, int id = 0, int ns = 0, int ne = m-1) {
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

int f(int xMn, int mx, int n) {

}

int main() {
    SaveTime
    int n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    build();
    int q; cin >> q;
    while (q--) {
        int xs,ys,xf,yf,k; cin >> xs >> ys >> xf >> yf >> k;
        xs--; ys--; xf--; yf--;
        bool ans = true;
        if (abs(ys-yf)%k != 0) {
            ans = false;
        }
        if (abs(xs-xf)%k != 0) {
            ans = false;
        }
        if (ys > yf) {
            swap(ys, yf);
        }
        if (ys == yf) {
            cout << (ans ? "YES\n" : "NO\n");
            continue;
        }
        int mx = get(ys, yf)-1;

//        cout << mx << '\n';
        int xMn = min(xs, xf);
        if (xMn <= mx) {
            int h = n-1-xMn;
//            cout << h << '\n';
            int hk=  h-h%k;
//            cout << hk << '\n';
            if (hk <= mx-xMn)
                ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}