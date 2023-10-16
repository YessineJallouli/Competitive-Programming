#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || k == i)
                        continue;
                    ans = min(ans, abs(a[i]-a[j]) + abs(a[i]-a[k]));
                }
            }
        }
        cout << ans << '\n';
    }
}