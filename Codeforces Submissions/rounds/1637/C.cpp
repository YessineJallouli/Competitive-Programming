#include <bits/stdc++.h>
#define SaveTime ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ans = false;
        for (int i = 1; i < n-1; i++) {
            if (a[i] != 1)
                ans = true;
        }
        if (n == 3 && a[1]%2 == 1)
            ans = false;
        if (! ans) {
            cout << -1 << '\n';
            continue;
        }
        ll res = 0;
        for (int i = 1; i < n-1; i++) {
            res = res + (a[i]+1)/2;
        }
        cout << res << '\n';
    }
}