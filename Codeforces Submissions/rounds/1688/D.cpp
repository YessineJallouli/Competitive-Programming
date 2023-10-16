#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int a[n];
        ll s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i]; s+= a[i];
        }
        if (k >= n) {
            ll b = k-n;
            cout << s + b*n + 1LL * n*(n-1)/2 << '\n';
        }
        else {
            s = 0;
            for (int i = 0; i < k; i++) {
                s+= a[i];
            }
            ll mx = s;
            for (int i = k; i < n; i++) {
                s+= a[i];
                s-= a[i-k];
                mx = max(mx, s);
            }
            cout << mx + 1LL*k*(k-1)/2 << '\n';
        }
    }
}