#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

void solve() {
    int n; cin >> n;
    double a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    if (n%2 == 0) {
        cout.precision(18);
        cout << fixed << (a[n-1]+a[n-2]-a[0]-a[1])/2.0  << '\n';
    }
    else {
        if (n == 5) {
            double ans1 = ((a[n-1]+a[n-2])/2.0)-((a[0]+a[2])/2.0);
            double ans2 =  ((a[n-1]+a[n-3])/2.0)-((a[0]+a[1])/2.0);
            if (ans1 < 0) ans1*=-1;
            if (ans2 < 0) ans2*=-1;
            cout.precision(18);
            cout << fixed << max(ans1, ans2) << '\n';
        }
        else {
            cout.precision(18);
            cout << fixed << (a[n-1]+a[n-2]-a[0]-a[1])/2.0  << '\n';
        }
    }
}

int main() {
    SaveTime
    freopen("here_comes_santa_claus_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        solve();
    }
}