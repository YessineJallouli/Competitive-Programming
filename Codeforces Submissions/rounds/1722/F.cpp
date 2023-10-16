#include <bits/stdc++.h>
#define ll unsigned long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1005;
int h[N][N];
ll pref[N][N];

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int g[n][m];
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == '.')
                    g[i][j] = 0;
                else
                    g[i][j] = 1;
            }
        }
        bool L = true;
        bool ans = true;
        while (L && ans) {
            L = false;
            for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < m-1; j++) {
                    int s = g[i][j]+g[i][j+1]+g[i+1][j]+g[i+1][j+1];
                    if (s == 3) {
                        L = true;
                        int s1 = 0;
                        for (int k = max(0, i-1); k <= min(n-1,i+2); k++) {
                            for (int l = max(0, j-1); l <= min(m-1,j+2); l++) {
                                s1+= g[k][l];
                            }
                        }
                        if (g[i][j] == 0) {
                            if (i > 0 && j > 0)
                                s1-= g[i-1][j-1];
                        }
                        if (g[i][j+1] == 0) {
                            if (i > 0 && j != m-2)
                                s1-= g[i-1][j+2];
                        }
                        if (g[i+1][j] == 0) {
                            if (i != n-2 && j != 0) {
                                s1-= g[i+2][j-1];
                            }
                        }
                        if (g[i+1][j+1] == 0) {
                            if (i != n-2 && j != m-2) {
                                s1-= g[i+2][j+2];
                            }
                        }
                        if (s1 != 3)
                            ans = false;
                        g[i][j] = g[i][j+1] = g[i+1][j] = g[i+1][j+1] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j])
                    ans = false;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }

}