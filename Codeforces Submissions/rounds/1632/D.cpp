#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 2e5+7;
int n;
int sieve[N];
int tree[4*N];

int mrg(int a, int b) {
    return __gcd(a,b);
}

int get(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
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

void upd(int pos, int val, int id = 0, int ns = 0, int ne = n-1) {
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

int main() {
    SaveTime
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int nb = 0;

    for (int i = 0; i < n; i++) {
        vector<int> prime;
        upd(i, a[i]);
        bool ok = true;
        if (a[i] == 1)
            ok = false;
        int l = 0, r = i;
        while (l <= r) {
            int m = (l+r)/2;
            int g = get(m,i);
            if (g > i-m+1)
                r = m-1;
            else if (g == i-m+1) {
                ok = false;
                break;
            }
            else
                l = m+1;
        }
        if (! ok) {
            upd(i, 1);
            nb++;
        }
        cout << nb << ' ';
    }
}