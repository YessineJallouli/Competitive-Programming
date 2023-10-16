#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime
    freopen("mosalah.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int total = n * (x + y);
        if (y == 0 && m < total) {
            cout << -1 << '\n';
        } else {
            cout << max(total - m,0) << '\n';
        }
    }
}