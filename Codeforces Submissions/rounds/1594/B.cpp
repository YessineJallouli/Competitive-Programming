#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int mod = 1e9+7;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        ll pw[40];
        pw[0] = 1;
        for (int i = 1; i < 40; i++) {
            pw[i] = (pw[i-1]*n)%mod;
        }
        ll p = 1;
        int nb = 0;
        while (p < k) {
            p*= 2;
            nb++;
        }
        ll ans = 0;
        while (true) {
            if (k == 0)
                break;
            if (p > k) {
                p/= 2;
                nb--;
            }
            else {
                ans = (ans + pw[nb])%mod;
                k-= p;
            }
        }
        cout << ans << '\n';
    }
}