#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("tabs.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        if (n == 1) {
            cout << 0 << '\n';
        }
        else if (k == 1 || k == n) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }
}