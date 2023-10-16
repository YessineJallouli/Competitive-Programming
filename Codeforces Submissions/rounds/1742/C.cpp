#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        char g[8][8];
        for (int i = 0; i < 8; i++) {
            string s; cin >> s;
            for (int j = 0; j < 8; j++) {
                g[i][j] = s[j];
            }
        }
        char ans;
        for (int i = 0; i < 8; i++) {
            int nb = 0;
            for (int j = 0; j < 8; j++) {
                if (g[i][j] == 'R')
                    nb--;
            }
            if (nb == -8) {
                ans = 'R';
            }
        }
        for (int i = 0; i < 8; i++) {
            int nb = 0;
            for (int j = 0; j < 8; j++) {
                if (g[j][i] == 'B')
                    nb++;
            }
            if (nb == 8) {
                ans = 'B';
            }
        }
        cout << ans << '\n';
    }
}