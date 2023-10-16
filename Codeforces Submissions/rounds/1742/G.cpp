#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool used[n];
        memset(used, false, sizeof used);
        int r = 0;
        for (int bit = 31; bit >= 0; bit--) {
            int best = -1;
            int mx = r;
            for (int i = 0; i < n; i++) {
                if (used[i])
                    continue;
                int k = (r|a[i]);
                if (k > mx) {
                    best = i;
                    mx = k;
                }
            }
            if (best != -1) {
                used[best] = true;
                r = mx;
                cout << a[best] << ' ';
            }
        }
        for (int i = 0; i < n; i++) {
            if (! used[i]) {
                cout << a[i] << ' ';
            }
        }
        cout << '\n';
    }
}