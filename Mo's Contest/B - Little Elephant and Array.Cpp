//https://codeforces.com/problemset/problem/220/B
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct query {
    int l,r,id;
    query() {
        l = r = id = 0;
    }
    query(int _l ,int _r, int _id) {
        l = _l;
        r = _r;
        id = _id;
    }
};
const int N = 1e5+7;
const int Q = 1e5+7;

int a[N];

int block;

bool cmp(query q1, query q2) {
    if (q1.l/block < q2.l/block)
        return true;
    if (q1.l/block == q2.l/block && q1.r < q2.r)
        return true;
    return false;
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
        int a,b; cin >> a >> b;
        qr[i] = query(a,b,i);
    }
    sort(qr, qr+q, cmp);
    int ans[q];
    int nb = 0;
    int l = 0, r = -1;
    unordered_map<int,int> cnt;
    for (int i = 0; i < q; i++) {
        auto [L,R,id] = qr[i];
        L--;
        R--;
        while (r < R) {
            r++;
            if (cnt[a[r]] == a[r])
                nb--;
            cnt[a[r]]++;
            if (cnt[a[r]] == a[r])
                nb++;
        }
        while (r > R) {
            if (cnt[a[r]] == a[r])
                nb--;
            cnt[a[r]]--;
            if (cnt[a[r]] == a[r])
                nb++;
            r--;
        }
        while (l < L) {
            if (cnt[a[l]] == a[l]) {
                nb--;
            }
            cnt[a[l]]--;
            if (cnt[a[l]] == a[l])
                nb++;
            l++;
        }
        while (l > L) {
            l--;
            if (cnt[a[l]] == a[l])
                nb--;
            cnt[a[l]]++;
            if (cnt[a[l]] == a[l])
                nb++;
        }
        ans[id] = nb;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}
