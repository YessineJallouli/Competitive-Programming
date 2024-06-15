#include <bits/stdc++.h>
#define ll long long
using namespace std;

// dp[i] := maximum number of session i can attend

const int N = 2e5+7;
pair<int,ll> tree[4*N];

pair<int,ll> mrg(pair<int,ll> x, pair<int,ll> y) {
    if (x.first > y.first)
        return x;
    if (x.first == y.first && x.second < y.second)
        return x;
    return y;
}


pair<int,ll> get(int qs, int qe, int id = 0, int ns = 0, int ne = N-1) {
    if (ns > qe || ne < qs) {
        return {0,-1}; // 0 for sum/gcd/or/xor and 1 for and/product and infinity for max/min
    }
    if (qs <= ns && qe >= ne) {
        return tree[id];
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

void upd(int pos, pair<int,ll> val, int id = 0, int ns = 0, int ne = N-1) {
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<tuple<ll,ll,ll>> v;
        set<ll> st;
        for (int i = 0; i < n; i++) {
            ll s,e,c; cin >> s >> e >> c;
            st.insert(s);
            st.insert(e);
            v.emplace_back(s,e,c);
        }
        map<ll,int> mp;
        int nb = 1;
        for (ll i : st) {
            mp[i] = nb++;
        }
        vector<tuple<int,int,ll>> a;
        for (int i = 0; i < n; i++) {
            auto [s,e,c] = v[i];
            a.emplace_back(mp[s], mp[e], c);
        }
        sort(a.begin(), a.end());
        for (auto [s,e,c] : a) {
            pair<int,ll> p = get(0, s-1);
            if (p.first == 0) {
                upd(e, {1,c});
            }
            else {
                pair<int,ll> p1 = get(e,e);
                pair<int,ll> p2 = p;
                p2.first = p.first+1;
                p2.second = max(c, p.second);
                p1 = mrg(p1, p2);
                upd(e, p1);
            }
        }
        int mx = 0;
        for (int i = 0; i <= 2*n; i++) {
            mx = max(mx, get(i,i).first);
        }
        ll ans = LLONG_MAX;
        for (int i = 0; i <= 2*n; i++) {
            if (get(i,i).first == mx) {
                ans = min(ans, get(i,i).second);
            }
        }
        cout << mx << ' ' << ans << '\n';
        for (int i = 0; i <= 2*n; i++) {
            upd(i, {0,0});
        }
    }
}
