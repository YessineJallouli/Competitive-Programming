#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e5+7;
vector<int> dv[N];
vector<tuple<int,int,int>> weights;

ll tree[4*N];


ll mrg(ll x, ll y) {
    return x+y;
}

ll get(int qs, int qe, int id = 0, int ns = 0, int ne = N-1) {
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
        tree[id] += val;
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    for (int i = 1; i < N; i++)
        dv[i].push_back(1);

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j+= i)
            dv[j].push_back(i);
    }


    for (int k = 2; k < N/2; k++) {
        for (int i : dv[2*k]) {
            int cnt = 0;
            for (int j : dv[2*k]) {
                if ((((j > i) && (k%j != 0 || k%i != 0) && (2*k < i+j+k)) || ((j > i) && (k%j == 0 && k%i == 0))) && (j < k)){
                    cnt++;
                }
            }
            weights.emplace_back(i,k,cnt);
        }
    }
    int q; cin >> q;
    tuple<int,int,int> qr[q];
    for (int i = 0; i < q; i++) {
        int l,r; cin >> l >> r;
        qr[i] = {r,l,i};
    }
    sort(qr, qr+q);
    ll ans[q];

    int lp = 0;

    for (int i = 0; i < q; i++) {
        auto [r,l,id] = qr[i];
        while (lp != (int) weights.size()) {
            auto [I,k,cnt] = weights[lp];
            if (k > r)
                break;
            upd(I, cnt);
            lp++;
        }
        ll k = r-l+1;
        ans[id] = k*(k-1)*(k-2)/6 - get(l,r);
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}