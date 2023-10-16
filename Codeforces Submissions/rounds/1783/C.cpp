//
// Created by yessine on 01/08/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        vector<pair<int,int>> v;
        int a[n];
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            v.emplace_back(x,i);
            a[i] = x;
        }
        sort(v.begin(), v.end());
        int nb = 0;
        int s = 0;
        for (auto [x, pos] : v) {
            if (s+x <= m) {
                s += x;
                nb++;
            }
        }
        if (nb == n) {
            cout << 1 << '\n';
            continue;
        }
        if (nb == 0) {
            cout << n+1 << '\n';
            continue;
        }

        int rk = n-nb;


        int k = a[nb];
        int cnt = 1;
        for (auto [x, pos] : v) {
            if (pos == nb)
                continue;
            if (k + x <= m) {
                k+= x;
                cnt++;
            }
        }
        if (cnt != nb || a[nb] > m)
            rk++;
        cout << rk << '\n';
    }
}