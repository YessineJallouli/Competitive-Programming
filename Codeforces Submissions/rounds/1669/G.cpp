#include <bits/stdc++.h>
#define ll long long
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
        char grid1[n][m];
        while (true) {
            bool mov = false;
            for (int j = 0; j < m; j++) {
                grid1[n-1][j] = grid[n-1][j];
            }
            for (int i = n-2; i >= 0; i--) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '*' && grid[i+1][j] == '.') {
                        mov = true;
                        grid1[i+1][j] = '*';
                        grid1[i][j] = '.';
                    }
                    else
                        grid1[i][j] = grid[i][j];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = grid1[i][j];
                }
            }
            if (! mov)
                break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}