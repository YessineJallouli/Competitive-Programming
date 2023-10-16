#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        vector<int> v;
        for (int i = 1; i < n-1; i++) {
            if (a[i] > a[i-1]+a[i+1]) {
                ans++;
            }
        }
        if (k != 1) {
            cout << ans << '\n';
        }
        else {
            cout << (n-1)/2 << '\n';
        }
    }
}