#include <bits/stdc++.h>
#define ll unsigned long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[n-i-1];
        }
        ll sum = 0;
        for (int i = 0; i < n-1; i++) {
            sum+= abs(a[i]-a[i+1]);
        }
        ll ans = sum;
        for (int i = 0; i < n; i++) {
            /// a[i] = a[i+1]
            ll x;
            if (i != n-1) {
                x = sum-abs(a[i]-a[i+1]);
                if (i != 0)
                    x = x + abs(a[i+1]-a[i-1]) - abs(a[i]-a[i-1]);
                ans = min(ans, x);
            }
            /// a[i] = a[i-1]
            if (i != 0) {
                x = sum - abs(a[i] - a[i - 1]);
                if (i != n-1)
                   x = x + abs(a[i + 1] - a[i - 1]) - abs(a[i] - a[i + 1]);
                ans = min(ans, x);
            }
        }
        cout << ans << '\n';
    }
}