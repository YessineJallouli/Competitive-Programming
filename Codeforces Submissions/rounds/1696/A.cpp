#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,z; cin >> n >> z;
        int a[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans = max(ans, a[i] | z);
        }
        cout << ans << '\n';
    }
}