#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        ll mn = 1e9+7, mx = 0;
        ll c1 = INT_MAX, c2 = INT_MAX;
        ll c3 = INT_MAX;
        map<pair<ll,ll>, bool> m;
        for (ll i = 0; i < n; i++) {
            ll a,b,c; cin >> a >> b >> c;
            if (a < mn) {
                c1 = c;
                mn = a;
            }
            if (b > mx) {
                c2 = c;
                mx = b;
            }
            if (a == mn) {
                c1 = min(c1, c);
            }
            if (b == mx) {
                c2 = min(c2, c);
            }
            if (a == mn && b == mx) {
                if (m[{mn, mx}])
                    c3 = min(c3, c);
                else
                   c3 = c;
            }
            m[{a,b}] = true;
            //cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
            if (m[{mn, mx}]) {
                cout << min(c1 + c2, c3) << '\n';
            }
            else {
                cout << c1+c2 << '\n';
            }
        }
    }
}