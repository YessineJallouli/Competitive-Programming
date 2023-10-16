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
        int ans = n;
        if (n == 1)
            ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                double diff = (a[j]-a[i])*1.0/(j-i);
                int nb = 0;
                for (int k = 0; k < n; k++) {
                    if (j == k)
                        continue;
                    double df = (a[k] - a[j]) * 1.0 / (k - j);
                    if (abs(df - diff) < 1e-6)
                        continue;
                    nb++;
                }
                ans = min(ans, nb);
            }
        }
        cout << ans << '\n';
    }
}