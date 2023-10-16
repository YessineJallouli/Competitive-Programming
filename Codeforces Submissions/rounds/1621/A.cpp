#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int nb = (n+1)/2;
        if (k > nb) {
            cout << -1 << '\n';
            continue;
        }
        char ans[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                ans[i][j] = '.';
        }
        for (int i = 0; i < 2*k; i+= 2) {
            ans[i][i] = 'R';
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
}