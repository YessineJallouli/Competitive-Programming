#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        int nb = 0;
        int mx = 0;
        for (int i = 0; i < n-1; i++) {
            int d = a[i+1]-a[i];
            if (d > k)
                nb = 0;
            else {
                nb++;
                mx = max(nb, mx);
            }
        }
        cout << n-(mx+1) << '\n';
    }
}