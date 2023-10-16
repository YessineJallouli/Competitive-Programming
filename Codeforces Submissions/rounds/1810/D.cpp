//
// Created by yessine on 3/31/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll,ll> intersection(pair<ll, ll> a, pair<ll,ll> b) {
    if (a.first == -1)
        return b;
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    if (max(x1, x2) > min(y1, y2))
        return {-1, -1};
    return {max(x1, x2), min(y1, y2)};
}

bool tr(ll n, ll days, ll a, ll b) {
    if (days <= 1)
        return false;
    return  (((days-2)*(a-b) + a) < n);
}

ll numberofdays(ll n, ll a, ll b) {
    if (a >= n)
        return 1;
    ll mx = (n+a)/(a-b);
    ll mn = 2;
    ll ans = -1;
    while (mn <= mx) {
        ll m = (mx+mn)/2;
        if (tr(n, m, a, b)) {
            ans = m;
            mn = m+1;
        }
        else {
            mx = m-1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int q; cin >> q;
        pair<ll,ll> information = {-1, -1};
        while (q--) {
            int t; cin >> t;
            if (t == 1) {
                ll a,b,n; cin >> a >> b >> n;
                ll mn = (a-b)*(n-2) + a+1;
                if (n == 1)
                    mn = 1;
                ll mx = (a-b)*(n-1) + a;
                pair<ll,ll> newInt = {mn, mx};
                if (intersection(information, newInt).first == -1) {
                    cout << 0 << ' ';
                }
                else {
                    cout << 1 << ' ';
                    information = intersection(information, newInt);
                }
            }
            else {
                ll a,b; cin >> a >> b;
                if (information.first == -1) {
                    cout << -1 << ' ';
                }
                else {
                    ll n1 = numberofdays(information.first, a, b);
                    ll n2 = numberofdays(information.second, a, b);
                    if (n1 == n2) {
                        cout << n1 << ' ';
                    } else {
                        cout << -1 << ' ';
                    }
                }
            }
        }
        cout << '\n';
    }
}