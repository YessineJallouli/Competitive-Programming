#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll n,c; cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll l = 1, r = sqrt(c/n);
        ll w = -1;
        while (l <= r) {
            ll m = (l+r)/2;
            ll s = 0;
            for (int i = 0; i < n; i++) {
                s+= 1LL*(a[i]+m)*(a[i]+m);
            }
            if (s <= c) {
                w = m;
                l = m+1;
            }
            else {
                r= m-1;
            }
        }
        cout << w/2 << '\n';
    }
}