#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5007;
ll a[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    ll n; cin >> n;
    ll ans = LLONG_MAX;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    if (n == 2) {
        cout << 1 << '\n';
        return 0;
    }
    for (int z = 0; z < n; z++) {
        ll b[n];
        for (int i = 0; i < n; i++)
            b[i] = a[i];
        b[z] = 0;
        ll nb = 2;
        for (int j = z+1; j < n-1; j++) {
            if (b[j+1] > b[j]) {
                nb++;
                continue;
            }
            ll k = b[j]/b[j+1]+1;
            b[j+1]*= k;
            nb+= k;
        }
        for (ll j = z-1; j > 0; j--) {
            if (b[j-1] > b[j]) {
                nb++;
                continue;
            }
            ll k = b[j]/b[j-1]+1;
            b[j-1]*= k;
            nb+= k;
        }
        ans = min(ans, nb);
    }
    cout << ans;
}