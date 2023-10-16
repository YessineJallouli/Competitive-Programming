#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = INT_MAX;
        for (int mx = 1; mx <= 3101; mx++) {
            int mn = INT_MAX;
            int nx = 0;
            int id = 1;
            for (int i = 0; i < n ; i++) {
                while (id != k && a[i]/id > mx)
                    id++;
                mn = min(mn, a[i]/id);
                nx = max(nx, a[i]/id);
            }
            ans = min(ans, nx-mn);
        }
        cout << ans << '\n';
    }
}