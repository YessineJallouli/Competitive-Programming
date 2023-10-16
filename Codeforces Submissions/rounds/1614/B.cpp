#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    ll T; cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        pair<ll, ll> a[n];
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            a[i] = {x, i};
        }
        sort(a, a + n, greater<pair<ll, ll>>());
        ll ans[n+1];
        ans[0] = 1;
        ll nb1 = 2;
        ll nb2 = 0;
        ll dist = 0;
        for (ll i = 1; i <= n; i+=2) {
            ans[a[i-1].second+1] = nb1;
            dist+= 2*abs(nb1-ans[0])*a[i-1].first;
            if (i+1 <= n) {
                ans[a[i].second+1] = nb2;
                dist+= 2*abs(nb2-ans[0])*a[i].first;
            }
            nb1++;
            nb2--;
        }
        cout << dist << '\n';
        for (ll i = 0; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}