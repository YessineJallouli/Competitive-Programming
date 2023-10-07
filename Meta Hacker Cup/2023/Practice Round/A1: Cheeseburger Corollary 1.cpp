#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

/// Global variables

void solve() {
    int s,d,k; cin >> s >> d >> k;
    if (s+2*d >= k && 2*(s+d) >= k+1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    SaveTime
    freopen("cheeseburger_corollary_1_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        solve();
    }
}
