#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans+= a[i]-a[0];
        cout << ans << '\n';
    }
}