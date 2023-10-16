#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

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
        if (n%2 == 0) {
            cout << "YES\n";
            continue;
        }
        bool ans = false;
        for (int i = 0; i < n-1; i++) {
            if (a[i] >= a[i+1]) {
                ans = true;
            }
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}