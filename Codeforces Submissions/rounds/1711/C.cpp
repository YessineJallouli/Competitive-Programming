#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll T; cin >> T;
    while (T--) {
        ll n,m,k; cin >> n >> m >> k;
        ll s = 0;
        ll a[k];
        for (ll i = 0; i < k; i++) {
            cin >> a[i];
            s+= a[i];
        }
        if (n*m > s) {
            cout << "NO\n";
            continue;
        }
        bool ans = false;
        for (ll t = 0; t < 2; t++) {
            ll b[k];
            for (ll i = 0; i < k; i++) {
                b[i] = a[i]/n;
            }
            sort(b, b+k);
            ll sum = 0;
            for (ll i = k-1; i >= 0; i--) {
                if (b[i] == 1)
                    continue;
                sum+= b[i];
            }
            if (m%2 == 0) {
                if (sum >= m) {
                    ans = true;
                }
            }
            else {
                if (sum >= m && sum % 2) {
                    ans = true;
                }
                else if (sum >= m) {
                    for (ll i = 0; i < k; i++) {
                        if (b[i] <= 1)
                            continue;
                        if (b[i] != 2)
                            ans = true;
                    }
                }
            }
            swap(n,m);
        }
        cout << (ans ? "Yes\n" : "No\n");
    }

}