#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        ll ans = LLONG_MAX;
        for (ll x = 0; x*x <= n; x++) {
            ll d = n-x*x;
            ll y = sqrtl(d);
            ans = min(ans, abs(x*x+y*y-n));
            y++;
            ans = min(ans, abs(x*x+y*y-n));
        }
        cout << ans << '\n';
    }
}
