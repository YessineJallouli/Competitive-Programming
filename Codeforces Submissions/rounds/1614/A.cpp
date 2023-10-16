#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    ll T; cin >> T;
    while (T--) {
        ll n,l,r,k; cin >> n >> l >> r >> k;
        ll a[n];
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        ll nb = 0;
        for (ll i = 0; i < n; i++) {
            if (!(a[i] >= l && a[i] <= r))
                continue;
           // cout << a[i] << ' ' << '\n';
            if (k-a[i] < 0)
                break;
            if (k-a[i] >= 0)
               k-= a[i];
            nb++;
            if (k == 0)
                break;
        }
        cout << nb << '\n';
    }
}