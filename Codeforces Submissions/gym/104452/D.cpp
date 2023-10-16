#include <bits/stdc++.h>
#define ll long long
using namespace std;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    int n; cin >> n;
    double a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    double k = (a[0]+a[n-1])/2.0;
    double mx = 1e10;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]-k) < mx) {
            ans = a[i];
            mx = abs(a[i]-k);
        }
    }
    cout << ans;
}