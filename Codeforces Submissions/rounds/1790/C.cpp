#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int cntF[n+1];
        int cntL[n+1];
        memset(cntF, 0, sizeof cntF);
        memset(cntL, 0, sizeof cntL);
        int F,L;
        map<pair<int,int>, int> m;
        int p[n][n];
        int next[n+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                cin >> p[i][j];
                int x = p[i][j];
                if (j == 0) {
                    cntF[x]++;
                }
                if (j == n-2) {
                    cntL[x]++;
                }
                if (cntF[x] == n-1)
                    F = x;
                if (cntL[x] == n-1) {
                    L = x;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                int x = p[i][j];
                if (j != 0) {
                    m[{p[i][j-1], x}]++;
                    if (m[{p[i][j-1], x}] == n-2) {
                        if (p[i][j-1] != F || x != L)
                            next[p[i][j - 1]] = x;
                    }
                }
            }
        }
        while (F != L) {
            cout << F << ' ';
            F = next[F];
        }
        cout << L << '\n';
    }
}