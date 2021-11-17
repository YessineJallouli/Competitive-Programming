//https://codeforces.com/problemset/problem/86/D
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct query {
    int L,R,id;
    query() {
        L = R = id = 0;
    }
    query(int _L, int _R,  int _id) {
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

const int N = 2e5+7;
const int NN = 1e6+7;
ll occ[NN];
ll a[N];

ll nb = 0;

void ins(int id) {
    nb+= a[id]*(2*occ[a[id]]+1);
    occ[a[id]]++;
}

void del(int id) {
    nb+= a[id]*(1-2*occ[a[id]]);
    occ[a[id]]--;
}

int main() {
    SaveTime
    int n,q; cin >> n >> q;
    block = sqrt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    query qr[q];
    for (int i = 0; i < q; i++) {
        int L,R; cin >> L >> R;
        qr[i] = query(L,R,i);
    }
    sort(qr, qr+q, cmp);
    ll ans[q];
    int l = 0, r = -1;
    for (int i = 0; i < q; i++) {
        auto [L,R,id] = qr[i];
        L--; R--;
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
        ans[id] = nb;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}
