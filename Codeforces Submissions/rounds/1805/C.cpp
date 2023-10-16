//
// Created by yessine on 4/2/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isSq(ll x) {
    ll h = sqrt(x);
    return (h*h == x);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        vector<int> k(n);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }
        sort(k.begin(), k.end());
        for (int i = 0; i < m; i++) {
            ll a,b,c; cin >> a >> b >> c;
            if (a*c <= 0) {
                cout << "NO\n";
                continue;
            }
            ll lower = ceil(-sqrt(4*a*c)) + b;
            ll upper = sqrt(4*a*c) +b;
            if (isSq(4*a*c)) {
                upper--;
                lower++;
            }
            int low = lower_bound(k.begin(), k.end(), lower) - k.begin();
            if (low != n && k[low] <= upper) {
                cout << "YES\n";
                cout << k[low] << '\n';
            }
            else {
                cout << "NO\n";
            }
        }
        cout << '\n';
    }
}