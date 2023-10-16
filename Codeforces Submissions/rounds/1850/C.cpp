#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n = 8;
        char g[n][n];
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++)
                g[i][j] = s[j];
        }
        string ans;
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = 0; j < n; j++) {
                if (g[i][j] != '.') {
                    while (i != 8 && g[i][j] != '.') {
                        ans+= g[i][j];
                        i++;
                    }
                    ok = true;
                    break;
                }
            }
            if (ok)
                break;
        }
        cout << ans << '\n';
    }
}