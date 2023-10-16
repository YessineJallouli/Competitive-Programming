#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans[n];
        memset(ans, 0, sizeof ans);
        int iq = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= iq) {
                ans[i] = 1;
            }
            if (a[i] > iq && iq != q) {
                iq++;
                ans[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << '\n';
    }
}