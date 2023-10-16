#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        ll dp[n];
        for (int i = 1; i < n-1; i+= 2) {
            int mx = max({a[i+1], a[i-1]});
            if (mx >= a[i])
                ans+= mx-a[i]+1;
            dp[i] = ans;
        }
        if (n%2)
            cout << ans << '\n';
        else {
            ll dp1 = 0;
            for (int i = n-2; i >= 2; i-= 2) {
                int mx = max({a[i+1], a[i-1]});
                if (mx >= a[i])
                    dp1+= mx-a[i]+1;
                if (i == 2) {
                    ans = min(ans, dp1);
                }
                else {
                    ans = min(ans, dp1+dp[i-3]);
                }
            }
            cout << ans << '\n';
        }
    }
}