#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        string ch[n];
        for (int i = 0; i < n; i++) {
            cin >> ch[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i <n; i++) {
            for (int j = i+1; j < n; j++) {
                int s = 0;
                for (int k = 0; k < m; k++) {
                    s+= abs(ch[i][k]-ch[j][k]);
                }
                ans = min(ans, s);
            }
        }
        cout << ans << '\n';
    }
}