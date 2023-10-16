#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (a[i]%a[0] != 0)
                ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}