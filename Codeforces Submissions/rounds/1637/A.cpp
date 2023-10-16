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
        int mx[n], mn[n];
        mx[0] = a[0];
        mn[n-1] = a[n-1];
        for (int i = 1; i <n; i++) {
            mx[i] = max(a[i-1], a[i]);
        }
        for (int i = n-2; i >= 0; i--) {
            mn[i] = min(mn[i+1], a[i]);
        }
        bool ans = false;
        for (int i = 0; i < n-1; i++) {
            if (mx[i] > mn[i+1])
                ans = true;
        }
        if (ans) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}