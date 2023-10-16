//
// Created by yessine on 1/10/23.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll calc(ll d, ll f) {
    ll sum = 0;
    ll ans = 0;
    for (ll bit = 0; bit <= 62; bit++) {
        ll k = ((1LL << bit) & d);
        if (k == 0) {
            sum+= (1LL << bit);
            continue;
        }
        if (sum + d+1 > f) {
            ans+= (1LL << bit);
        }
    }
    return ans;
}

int main() {
    //cout << (1LL << 62) + (1LL << 61);
    int T; cin >> T;
    while (T--) {
        ll n,x; cin >> n >> x;
        if (x > n) {
            cout << -1 << '\n';
        }
        else {
            ll l = n,r = 5e18;
            ll ans;
            while (l <= r) {
                ll m = (l+r)/2;
                if (calc(n,m) <= x) {
                    r = m-1;
                    ans = m;
                }
                else {
                    l = m+1;
                }
            }
            if (calc(n,ans) == x) {
                cout << ans << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
}