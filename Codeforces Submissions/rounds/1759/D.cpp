//
// Created by yessine on 11/18/22.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int nbZ(ll k) {
    int nb = 0;
    while (k%10 == 0LL && k >= 10) {
        nb++;
        k/= 10;
    }
    return nb;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll n,m; cin >> n >> m;
        vector<ll> v;
        ll k = 1;
        while (k <= m) {
            k*= 5;
            v.push_back(k);
            ll p = 1;
            while (p <= m) {
                p*= 2;
                v.push_back(p*k);
                v.push_back(p);
            }
        }


        ll ans = n*m;
        for (ll i : v) {
            if (i > m)
                continue;
            ll f = m/i*i;
            ll h = f*n;
            if (nbZ(h) > nbZ(ans)) {
                ans = h;
            }
            else if (nbZ(h) == nbZ(ans)) {
                ans = max(ans, h);
            }
        }
        cout << ans << '\n';
    }
}