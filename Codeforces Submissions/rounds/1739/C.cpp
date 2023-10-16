#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 998244353;

const int mx = 200;

long long dp[mx][mx];

long long C(int n, int k) {
    if (dp[n][k] != -1)
        return dp[n][k];
    if (k == n || k == 0)
        return dp[n][k] = 1;
    return dp[n][k] = (C(n-1, k) + C(n-1, k-1)) % mod;
}

int main() {
    memset(dp, -1, sizeof dp);
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll ans = 0;
        for (int i = n; i >= 2; i-= 2) {
            // I have ith card
            if ((n-i)%4 == 0)
                ans = (ans + C(i-1, i/2-1))%mod;
            else
                ans = (ans + C(i-2, i/2-2))%mod;
        }
        ll s = C(n, n/2);
        s = (s-ans-1+mod)%mod;
        cout << ans << ' ' << s << ' ' << 1 << '\n';
    }
}