#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            if (a[i] > a[i+1]) {
                ans++; i++;
            }
        }
        cout << ans << '\n';
    }
}