//
// Created by yessine on 6/6/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        if (s.size() <= 3) {
            cout << 0 << '\n';
            continue;
        }
        sort(a, a+n);
        int l = 1, r = 1e9;
        int ans = -1;
        while (l <= r) {
            bool can = false;
            int m = (l+r)/2;
            int k = a[0] +2*m+1;
            int d = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] >= k) {
                    d = a[i];
                    break;
                }
            }
            if (d == -1)
                can = true;
            else {
                k = d + 2 * m + 1;
                d = -1;
                for (int i = 0; i < n; i++) {
                    if (a[i] >= k) {
                        d = a[i];
                        break;
                    }
                }
                if (d == -1)
                    can = true;
                else {
                    k = d + 2 * m + 1;
                    if (a[n-1] < k)
                        can = true;
                }
            }
            if (can) {
                ans = m;
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        cout << ans << '\n';
    }
}