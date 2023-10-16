#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
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
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i < n-1 && j < m-1) {
                    if (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i][j + 1] + grid[i][j] == 3) {
                        ans = false;
                    }
                }
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}