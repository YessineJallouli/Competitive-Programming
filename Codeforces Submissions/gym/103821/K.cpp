#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool overlap(pair<int,int> p1, pair<int,int> p2) {
    if (p2.first > p1.second)
        return false;
    return true;
}


const int N = 2e5+2; // n max
pair<int,ll> tree[4*N];
int n,m;

int mod = 1e9+7;

pair<int,ll> mrg(pair<int,ll>  x, pair<int,ll> y) {
    pair<int,ll> res;
    res.first = x.first+y.first;
    res.second = x.second+y.second;
    return res;
}

pair<int,ll> get(int qs, int qe, int id = 0, int ns = 0, int ne = m) {
    if (ns > qe || ne < qs) {
        return {0,0}; // 0 for sum/gcd/or/xor and 1 for and/product and infinity for max/min
    }
    if (qs <= ns && qe >= ne) {
        return tree[id];
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

void upd(int pos, pair<int,ll> val, int id = 0, int ns = 0, int ne = m) {
    if (pos > ne || pos < ns)
        return;
    if (ns == ne) {
        tree[id] = {tree[id].first+val.first, tree[id].second+val.second};
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
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < 4*m; i++) {
            tree[i] = {0,0};
        }
        pair<int,int> movies[n];
        for (int i = 0; i < n; i++) {
            cin >> movies[i].first >> movies[i].second;
        }
        sort(movies, movies+n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            pair<int,ll> k = get(0, movies[i].first-1);
            ans+= 1LL * k.second * (m-movies[i].second+1);
            ans%= mod;
            upd(movies[i].second, {1,movies[i].first});
        }
        cout << ans << '\n';
    }
}