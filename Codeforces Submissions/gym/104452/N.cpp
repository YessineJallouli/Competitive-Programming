#include <bits/stdc++.h>
#define ll long long
using namespace std;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    const int mod = 1440;
    ll n,k; cin >> k >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    ll mx = 0;
    for (ll i = 0; i < n; i++) {
        if (sum+v[i] <= k) {
            sum+= v[i];
            mx++;
        }
    }
    ll ans = LLONG_MAX;
    do {
        ll s = 0;
        for (ll i = 0; i < mx; i++) {
            s+= v[i];
        }
        if (s > k)
            continue;
        ll cum = 0;
        ll res = 0;
        for (ll i = 0; i < mx; i++) {
            cum+= v[i];
            res+= cum;
        }
        for (ll day = 0; day <= 0; day++) {
            if (day+cum <= k) {
                ans = min(ans, (mx*day+res)%mod);
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << mx << ' ' << ans;
}