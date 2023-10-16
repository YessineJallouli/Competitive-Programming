//
// Created by Yessine on 7/8/22.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        vector<int> v(n, 0);
        for (int i = 0; i < m; i++) {
            int k; cin >> k;
            v[k-1]++;
        }
        sort(v.begin(), v.end());
        int l = 1, r = 2*m;
        int ans = -1;
        while (l <= r) {
            int md = (l+r+1)/2;
            bool can = false;
            ll nb = 0;
            for (int i = 0; i < n; i++) {
                nb+= min(md, v[i]);
                if (md > v[i])
                    nb+= (md-v[i])/2;
            }
            if (nb >= m) {
                can = true;
            }
            if (can) {
                r = md-1;
                ans = md;
            }
            else {
                l = md+1;
            }
        }
        cout << ans << '\n';
    }
}