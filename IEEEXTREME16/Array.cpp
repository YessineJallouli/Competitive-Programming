//100%
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+7; // n max
int n;
ll tree[4*N];

ll mrg(ll x, ll y) {
    return x+y;
}

ll get(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
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

void upd(int pos, ll val, int id = 0, int ns = 0, int ne = n-1) {
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

    int m,p; cin >> n >> m >> p;
    vector<pair<int,int>> constraints[n+1];
    for (int i = 0; i < m; i++) {
        int l,r,k; cin >> l >> r >> k;
        constraints[r].emplace_back(l,k);
    }

    bool contradiction = false;
    vector<tuple<int,int,int>> compressedConstraints;
    for (int i = n; i >= 1; i--) {
        if (constraints[i].empty())
            continue;
        sort(constraints[i].rbegin(), constraints[i].rend());
        auto [L,K] = constraints[i][0];
        map<int, int> mp;
        for (auto [l,k] : constraints[i]) {
            if (mp.count(l)) {
                if (mp[l] != k)
                    contradiction = true;
            }
            else
                mp[l] = k;
        }
        for (int j = 1; j < constraints[i].size(); j++) {
            auto [l,k] = constraints[i][j];
            if (l == L)
                continue;
            int newR = L-1;
            int newL = l;
            int newK = (k-K+p)%p;
            constraints[newR].emplace_back(newL, newK);
        }
        compressedConstraints.emplace_back(i,L,K);
    }

    if (contradiction) {
        cout << "None";
        return 0;
    }
    sort(compressedConstraints.begin(), compressedConstraints.end());
    for (auto [r,l,k] : compressedConstraints) {
        r--;
        l--;
        ll sum = get(l,r)%p;
        ll rem = (k-sum+p)%p;
        upd(r,rem);
    }
    for (int i = 0; i < n; i++) {
        cout << get(i,i) << ' ';
    }
}
