#include <bits/stdc++.h>
#define SaveTime ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
using namespace std;

const ll N = 107;
ll a[N];
ll b[N];
ll dp[10007][N];
ll n;


void solve(ll sum = 0, ll id = 0) {
    if (dp[sum][id] == 1)
        return;
    dp[sum][id] = 1;
    if (id == n)
        return;
    solve(sum+a[id], id+1);
    solve(sum+b[id], id+1);
}

int main() {
    //SaveTime
    ll T; cin >> T;
    while (T--) {
        cin >> n;
        ll s1 = 0;
        ll ans = 0;
        for (ll i = 0; i< n; i++) {
            cin >> a[i];
            ans+= a[i]*a[i];
            s1+= a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
            ans+= b[i]*b[i];
            s1+= b[i];
        }
        ans*= n-2;
        for (ll i = 0; i <= n; i++) {
            for (ll j = 0; j <= 10000; j++)
                dp[j][i] = -1;
        }
        solve();
        ll sumMin = LLONG_MAX;
        for (ll i = n; i <= 10000; i++) {
            if (dp[i][n] == 1) {
                ll s2 = s1 - i;
                if ((s2 * s2 + i * i) < sumMin && dp[s2][n] == 1) {
                    sumMin = s2 * s2 + i * i;
                }
            }
        }
        if (sumMin == LLONG_MAX)
            sumMin = 0;
        ans += sumMin;
        cout << ans << '\n';
    }
}