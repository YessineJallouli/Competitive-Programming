#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int q; cin >> q;
        int a[n];
        int mx[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        mx[0] = a[0];
        for (int i = 1; i < n; i++) {
            mx[i] = max(mx[i-1], a[i]);
        }
        while (q--) {
            int i,k; cin >> i >> k;
            i--;
            if (a[i] == n) {
                int r = max(0, i-1);
                cout << max(0, k-r) << '\n';
            }
            else {
                if (mx[i] != a[i]) {
                    cout << 0 << '\n';
                }
                else {
                    int l = i, r = n-1;
                    int ans = -1;
                    while (l <= r) {
                        int m = (l+r)/2;
                        if (mx[m] == a[i]) {
                            ans = m;
                            l = m+1;
                        }
                        else {
                            r = m-1;
                        }
                    }
                    int nb = ans-i+1;
                    if (i == 0) {
                        nb--;
                    }
                    int R = max(0, i-1);
                    int NB = max(0, k-R);
                    cout << min(nb, NB) << '\n';
                }
            }
        }
    }
}