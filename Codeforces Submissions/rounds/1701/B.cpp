//
// Created by Yessine on 7/8/22.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        bool vis[n+1];
        cout << 2 << '\n';
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= n; i++) {
            if (vis[i])
                continue;
            int k = i;
            while (k <= n) {
                cout << k << ' ';
                vis[k] = true;
                k*= 2;
            }
        }
        cout << '\n';
    }
}