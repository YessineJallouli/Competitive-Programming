#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll s,k;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        cin >> s >> k;
        if (s%5 == 0) {
            cout << max(s*k, (s+s%10)*(k-1)) << '\n';
            continue;
        }
        ll ans = max(s*k, (s+s%10)*(k-1));
        s+= s%10;
        k--;
        if (k < 10) {
            for (int i = 0; i < k; i++) {
                s+= s%10;
                k--;
                ans = max(ans, s*k);
            }
            cout << ans << '\n';
            continue;
        }
        for (int i = 0; i < 4; i++) {
            //(s+20n)*(k-4n) = (sk+n(20k-4s)-80n)
            // maximum at -160n + 20k-4s = 0;
            ans = max(ans, s*k);
            ll n = (20*k-4*s)/160;
            for (ll nn = max(0LL, n-1); nn <= n+1; nn++) {
                if (nn < 0) break;
                ans = max(ans, (s+20*nn)*(k-4*nn));
            }
            s += s % 10;
            k--;
        }
        cout << ans << '\n';
    }
}