#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        int g[n][m];
        int nbO = 0;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j <m ; j++) {
                g[i][j] = s[j]-'0';
                nbO+= g[i][j];
            }
        }
        if (nbO == n*m) {
            cout << n*m-2 << '\n';
            continue;
        }
        bool b = false;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int s = g[i][j]+g[i-1][j]+g[i-1][j-1]+g[i][j-1];
                if (s < 3) {
                    b = true;
                }
            }
        }
        if (b) {
            cout << nbO << '\n';
        }
        else {
            cout << nbO-1 << '\n';
        }
    }
}