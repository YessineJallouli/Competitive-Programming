#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int n,k,r,c; cin >> n >> k >> r >> c;
        r--; c--;
        char g[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = '.';
            }
        }
        g[r][c] = 'X';
        for (int i = c+k; i < n; i+=k) {
            g[r][i] = 'X';
        }
        for (int i = c-k; i >= 0; i-=k) {
            g[r][i] = 'X';
        }

        for (int i = 0; i < n; i++) {
            int d = r-i;
            for (int j = 0; j < n; j++) {
                g[i][(j+d+n)%n] = g[r][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << g[i][j];
            }
            cout << '\n';
        }
    }
}