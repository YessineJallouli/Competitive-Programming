#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        ll c[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c[i][j];
            }
        }
        vector<pair<ll,int>> v(n);
        for (int i = 0; i < n; i++) {
            //ll s1 = 0, s2 = 0;
            ll s = 0;
            for (int j = 0; j < m; j++) {
                s+= c[i][j]*j;
            }
            v[i] = {s, i+1};
        }
        sort(v.rbegin(), v.rend());
        cout << v[0].second << ' ' << v[0].first-v.back().first << '\n';
    }
}