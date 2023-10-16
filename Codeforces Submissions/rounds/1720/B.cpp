#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int mx = 0;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        cout << a[n-1]+a[n-2]-a[0]-a[1] << '\n';
    }

}