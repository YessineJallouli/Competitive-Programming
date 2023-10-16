#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        int r,c; cin >> r >> c;
        r--;
        c--;
        char grid[n][m];
        bool ans = 0;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                grid[i][j] = s[j];
                if (grid[i][j] == 'B')
                    ans = true;
            }
        }
        bool ans2 = false;
        for (int i = 0; i < n; i++) {
            if (grid[i][c] == 'B')
                ans2 = true;
        }
        for (int i = 0; i < m; i++) {
            if (grid[r][i] == 'B')
                ans2 = true;
        }
        if (grid[r][c] == 'B')
            cout << 0 << '\n';
        else if (ans2)
            cout << 1 << '\n';
        else if (ans)
            cout << 2 << '\n';
        else
            cout << -1 << '\n';
    }
}