#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    //SaveTime
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        int grid[n][m];
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                grid[i][j] = s[j]-'0';
            }
        }
        bool ans = true;
        if (grid[0][0] == 1) {
            ans = false;
        }
        if (! ans) {
            cout << -1 << '\n';
            continue;
        }
        vector<tuple<int,int,int,int>> res;
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    if (i != 0) {
                        res.push_back({i,j+1, i+1, j+1});
                    }
                    else {
                        res.push_back({i+1, j, i+1, j+1});
                    }
                }
            }
        }
        cout << res.size() << '\n';
        for (auto [a,b,c,d] : res) {
            cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        }
    }
}