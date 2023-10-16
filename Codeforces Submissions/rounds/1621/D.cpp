#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int grid[2*n][2*n];
        for (int i = 0; i < 2*n; i++) {
            for (int j = 0; j < 2*n; j++) {
                cin >> grid[i][j];
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                ans+= grid[i][j];
        }
        for (int i = n; i < 2*n; i++) {
            for (int j = n; j < 2*n; j++)
                ans+= grid[i][j];
        }
        ans+= min({grid[0][n], grid[0][2*n-1], grid[n-1][n], grid[n-1][2*n-1], grid[n][0], grid[n][n-1], grid[2*n-1][0], grid[2*n-1][n-1]});
        cout << ans << '\n';
    }
}