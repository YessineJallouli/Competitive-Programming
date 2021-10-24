#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        char grid[n][m];
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                grid[i][j] = s[j];
            }
        }
        int n1, m1; cin >> n1 >> m1;
        char pattern[n1][m1];
        for (int i = 0; i < n1; i++) {
            string s; cin >> s;
            for (int j = 0; j < m1; j++) {
                pattern[i][j] = s[j];
            }
        }
        long long ans = 0;
        for (int shiftI = 0; shiftI+n1-1 < n; shiftI++) {
            for (int shiftJ = 0; shiftJ+m1-1 < m; shiftJ++) {
                bool ok = true;
                for (int i = 0; i < n1; i++) {
                    for (int j = 0; j < m1; j++) {
                        if (pattern[i][j] == '?')
                            continue;
                        if (pattern[i][j] != grid[i+shiftI][j+shiftJ]) {
                            ok = false;
                        }
                    }
                }
                if (ok)
                    ans++;
            }
        }
        cout << ans << '\n';
    }
}
