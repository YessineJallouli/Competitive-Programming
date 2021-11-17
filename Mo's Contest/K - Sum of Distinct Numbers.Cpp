//https://www.spoj.com/problems/XXXXXXXX/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct query {
    int L,R,t,id;
    query() {
        L = R = t = id = 0;
    }
    query(int _L, int _R, int _t, int _id) {
        L = _L;
        R = _R;
        t = _t;
        id = _id;
    }
};

int block;
const int N = 5e4+7;
const int Q = 1e5+7;

int a[N];
int occ[4*N];
int decode[4*N];
ll nb = 0;

pair<int,int> after[Q];
pair<int,int> before[Q];

bool cmp(query q1, query q2) {
    if (q1.L/block < q2.L/block)
        return true;
    if (q1.L/block == q2.L/block && q1.R/block < q2.R/block)
        return true;
    if (q1.L/block == q2.L/block && q1.R/block == q2.R/block && q1.t < q2.t)
        return true;
    return false;
}

void ins(int val) {
    occ[val]++;
    if (occ[val] == 1)
        nb+= decode[val];
}

void del(int val) {
    occ[val]--;
    if (occ[val] == 0)
        nb-= decode[val];
}

int main() {
    SaveTime
    int n,q; cin >> n;
    block = pow(n,2/3.0)+1;
    set<int> s;
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    cin >> q;
    vector<query> qr;
    int tmp = 0;
    for (int i = 0; i < q; i++) {
        char c; int x,y; cin >> c >> x >> y;
        if (c == 'U') {
            tmp++;
            x--;
            before[tmp] = {x,a[x]};
            after[tmp-1] = {x,y};
            a[x] = y;
            s.insert(y);
        }
        else {
            x--; y--;
            qr.push_back(query(x,y,tmp,i));
        }
    }
    int H = 1;
    for (int i : s) {
        m[i] = H;
        decode[H] = i;
        H++;
    }
    for (int i = 1; i <= tmp; i++) {
        before[i].second = m[before[i].second],
        after[i-1].second = m[after[i-1].second];
    }
    for (int i = 0; i < n; i++) {
        a[i] = m[a[i]];
    }
    sort(qr.begin(), qr.end(), cmp);
    ll ans[q];
    for (int i = 0; i < q; i++)
        ans[i] = LLONG_MAX;
    int l = 0, r = -1;
    for (int i = 0; i < qr.size(); i++) {
        auto [L,R,t,id] = qr[i];
        while (tmp > t) {
            auto[idx, val] = before[tmp];
            if (idx >= l && idx <= r) {
                occ[a[idx]]--;
                if (occ[a[idx]] == 0)
                    nb-= decode[a[idx]];
                occ[val]++;
                if (occ[val] == 1)
                    nb+= decode[val];
            }
            a[idx] = val;
            tmp--;
        }
        while (tmp < t) {
            auto[idx, val] = after[tmp];
            if (idx >= l && idx <= r) {
                occ[a[idx]]--;
                if (occ[a[idx]] == 0)
                    nb-= decode[a[idx]];
                occ[val]++;
                if (occ[val] == 1)
                    nb+= decode[val];
            }
            a[idx] = val;
            tmp++;
        }
        while (r < R) {
            r++;
            ins(a[r]);
        }
        while (r > R) {
            del(a[r]);
            r--;
        }
        while (l < L) {
            del(a[l]);
            l++;
        }
        while (l > L) {
            l--;
            ins(a[l]);
        }
        ans[id] = nb;
    }
    for (int i = 0; i < q; i++) {
        if (ans[i] == LLONG_MAX)
            continue;
        cout << ans[i] << '\n';
    }
}
