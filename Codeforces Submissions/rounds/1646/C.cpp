#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    //SaveTime
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        int ans = INT_MAX;
        vector<ll> fact;
        ll f = 1;
        ll h = 1;
        for (ll i = 0; i < 15; i++) {
            fact.push_back(f);
            h++;
            f*= h;
        }
        for (ll i = 0; i < (1 << 15); i++) {
            ll x = i;
            ll nb = 0;
            int res = 0;
            for (ll j = 0; j < 15; j++) {
                if (x & (1LL << j)) {
                    nb+= fact[j];
                    res++;
                }
            }
            if (nb > n)
                continue;
            ll rem = n-nb;
            for (ll i = 0; i < 40; i++) {
                ll h = (1LL << i);
                if (rem & h) {
                    res++;
                }
            }
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
}