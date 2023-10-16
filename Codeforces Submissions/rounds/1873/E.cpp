#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,x; cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll l = 1, r = 1e15;
        ll ans = -1;
        while (l <= r) {
            int m = (l+r)/2;
            ll k = 0;
            for (int i = 0; i < n; i++) {
                k+= max(0,m-a[i]);
            }
            if (k <= x) {
                ans = m;
                l = m+1;
            }
            else
                r = m-1;
        }
        cout << ans << '\n';

    }
}