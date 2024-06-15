#include <bits/stdc++.h>
#define ll long long
using namespace std;

int neutral;

const int N = 2e5+2; // n max
int n;
int a[N], tree[4*N];

int mrg(int x, int y) {
    return x&y;
}

void build(int id = 0, int ns = 0, int ne = n-1) {
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

int get(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
    if (ns > qe || ne < qs) {
        return neutral; // 0 for sum/gcd/or/xor and 1 for and/product and infinity for max/min
    }
    if (qs <= ns && qe >= ne) {
        return tree[id];
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    neutral = 0;
    for (int i = 0; i < 20; i++) {
        neutral+= (1<<i);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build();
    int nd = a[0];
    for (int i = 0; i < n; i++) {
        nd&= a[i];
    }
    vector<pair<int,int>> v;
    int L[n];
    int R[n];
    for (int i = 0; i < n; i++) {
        int l = i, r = n-1;
        int ans = -1;
        while (l <= r) {
            int m = (l+r)/2;
            if (get(i,m) > nd) {
                l = m+1;
            }
            else {
                ans = m;
                r = m-1;
            }
        }
        if (ans != -1) {
            v.emplace_back(i+1, ans+1);
            L[i] = ans;
            R[ans] = i;
        }
    }

    int q; cin >> q;
    while (q--) {
        int x,y; cin >> x >> y;
        x--; y--;
        bool ans = true;
        if (x == 0 && y == n-1) {
            if (nd != 0)
                ans = false;
        }
        else {
            int d = get(x,y);
            if (d != nd) {
                ans = false;
            }
            else {
                int fin = L[x];
                int deb = R[fin];
                int k = get(0, deb-1) & get(fin+1, n-1);
                if (k != nd)
                    ans = false;
            }
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
