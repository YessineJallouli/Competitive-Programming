//
// Created by yessine on 4/4/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll pw9[18];
ll pw10[18];

ll idx(ll k) {
    if (k < 4)
        return k;
    if (k < 10)
        return k-1;

    string s = to_string(k);
    ll n = (int) s.size()-1;
    ll h = s[0]-'0';
    if (h < 4) {
        return h * pw9[n] + idx(k - h*pw10[n]);
    }
    else if (h == 4){
        return h * pw9[n]-1;
    }
    else {
        return (h-1) * pw9[n] + idx(k - h*pw10[n]);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    pw9[0] = 1;
    pw10[0] = 1;
    for (int i = 1; i < 18; i++) {
        pw9[i] = pw9[i-1]*9;
        pw10[i] = pw10[i-1]*10;
    }
    int T; cin >> T;
    while (T--) {
        ll k; cin >> k;
        ll l = 1, r = 1e18;
        ll ans = -1;
        while (l <= r) {
            ll m = (l+r)/2;
            if (idx(m) >= k) {
                ans = m;
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        cout << ans << '\n';

    }
}