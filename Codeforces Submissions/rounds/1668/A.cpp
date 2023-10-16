#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        if (n > m)
            swap(n,m);
        if (n+m == 2) {
            cout << "0\n";
        }
        else if (n == 1 && m == 2) {
            cout << 1 << '\n';
        }
        else if (n == 1) {
            cout << -1 << '\n';
        }
        else {
            int ans = n+m-2;
            int diff = m-n;
            if (diff%2)
                diff--;
            cout << ans+diff << '\n';
        }
    }
}