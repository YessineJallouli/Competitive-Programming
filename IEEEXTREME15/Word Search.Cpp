#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,c; cin >> n >> m >> c;
    char grid[n][m];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
        }
    }
    map<string, tuple<int,int,int,int>> ans;
    string ss[c];
    for (int i = 0; i < c; i++) {
        string s; cin >> s;
        ss[i] = s;
        ans[s] = {INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    }
    for (int i = 0; i < n; i++) {
        for (int j =0; j < m; j++) {
            string ch = "";
            /// move -->
            for (int k = j; k < m; k++) {
                ch+= grid[i][k];
                if (ans.count(ch)) {
                    ans[ch] = min(ans[ch], {i,j,i,k});
                }
            }
            /// move <--
            ch = "";
            for (int k = j; k >= 0; k--) {
                ch+= grid[i][k];
                if (ans.count(ch)) {
                    ans[ch] = min(ans[ch], {i,j,i,k});
                }
            }
            /// move v
            ch = "";
            for (int k = i; k < n; k++) {
                ch+= grid[k][j];
                if (ans.count(ch)) {
                    ans[ch] = min(ans[ch], {i,j,k,j});
                }
            }
            /// move ^
            ch = "";
            for (int k = i; k >= 0; k--) {
                ch+= grid[k][j];
                if (ans.count(ch)) {
                    ans[ch] = min(ans[ch], {i,j,k,j});
                }
            }
            /// diag
            ch = "";
            int di = i, dj = j;
            while (true) {
                if (di == n || dj == m) {
                    break;
                }
                ch+= grid[di][dj];
                if (ans.count(ch)) {
                    ans[ch] = min(ans[ch], {i,j,di,dj});
                }
                di++; dj++;
            }
            /// diag p
            ch = "";
            di = i, dj = j;
            while (true) {
                if (di == -1 || dj == -1) {
                    break;
                }
                ch+= grid[di][dj];
                if (ans.count(ch)) {
                    ans[ch] = min(ans[ch], {i,j,di,dj});
                }
                di--; dj--;
            }
            /// diag 2;
            ch = "";
            di = i; dj = j;
            while (true) {
                if (dj == -1 || di == n) {
                    break;
                }
                ch+= grid[di][dj];
                if (ans.count(ch)) {
                    ans[ch] = min(ans[ch], {i,j,di,dj});
                }
                di++; dj--;
            }
            /// diag 2 p;
            ch = "";
            di = i; dj = j;
            while (true) {
                if (dj == m || di == -1) {
                    break;
                }
                ch+= grid[di][dj];
                if (ans.count(ch)) {
                    ans[ch] = min(ans[ch], {i,j,di,dj});
                }
                di--; dj++;
            }
        }
    }
    for (int i = 0; i < c; i++) {
        auto [a,b,c,d] = ans[ss[i]];
        if (a != INT_MAX) {
            cout << a << ' ' << b << ' ' << c << ' '<< d << '\n';
        }
        else
            cout << -1 << '\n';
    }
}
