#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        int grid[n][m];
        vector<int> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int d1 = abs(n-1-i) + abs(m-1-j);
                int d2 = abs(n-1-i) + abs(j);
                int d3 = abs(i) + abs(m-1-j);
                int d4 = abs(i) + abs(j);
                v.push_back(max({d1,d2,d3,d4}));
            }
        }
        sort(v.begin(), v.end());
        for (int i : v)
            cout << i << ' ';
        cout << '\n';
    }
}