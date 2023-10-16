#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int p[n];
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (p[i] > k) {
                for (int j = k; j < n; j++) {
                    if (p[j] <= k) {
                        swap(p[i], p[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}