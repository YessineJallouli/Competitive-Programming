#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int k; cin >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int nb = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] & (1 << i))
                    continue;
                nb++;
            }
            if (nb <= k) {
                k-= nb;
                ans+= (1 << i);
            }
        }
        cout << ans << '\n';
    }
}