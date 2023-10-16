#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> pos(n+1);
        for (int i = 0; i < n; i++) {
            int c; cin >> c;
            pos[c].push_back(i);
        }
        for (int c = 1; c <= n; c++) {
            int len = (int) pos[c].size();
            int ans = 0;
            for (int p = 0; p < 2; p++) {
                bool odd = (p == 1);
                int nb = 0;
                for (int i = 0; i < len; i++) {
                    if (odd && pos[c][i]%2 == 1) {
                        odd = false;
                        nb++;
                    }
                    if (! odd && pos[c][i]%2 == 0) {
                        odd = true;
                        nb++;
                    }
                }
                ans = max(ans, nb);
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
}