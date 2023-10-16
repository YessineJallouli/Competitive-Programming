#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456");
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i]-a[(i+1)%n]);
    }
    for (int i = 0; i < n; i++) {
        int mn = INT_MAX;
        int mx = 0;
        for (int j = i; j < n; j++) {
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            if (j != n-1) {
                ans = max(ans, a[n-1]-mn);
            }
            if (i != 0) {
                ans = max(ans, mx-a[0]);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    int T; cin >> T;
    while (T--) {
        solve();
    }
}