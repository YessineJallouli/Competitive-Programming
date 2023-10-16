#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        if (n+m == 2) {
            cout << 0 << '\n';
            continue;
        }
        int dist = n+m-2;
        int mx = max(n,m);
        cout << dist*2-mx+2 << '\n';
    }
}