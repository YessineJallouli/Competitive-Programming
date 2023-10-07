#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

/// Global variables

void solve() {
    int r,c,a,b; cin >> r >> c >> a >> b;
    if (r > c) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    SaveTime
    freopen("dim_sum_delivery_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        solve();
    }
}
