//
// Created by ramizouari on 14/10/2021.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    int L,C; cin >> L >> C;
    char grid[L][C];
    for (int i = 0; i < L; i++) {
        string s; cin >> s;
        for (int j = 0; j < C; j++) {
            grid[i][j] = s[j];
        }
    }
    map<string, bool> m;
    int nb; cin >> nb;
    for (int i = 0; i < nb; i++) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        m[s] = true;
    }
    set<string> cnt[L][C];
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            string ch = "";
            /// move -->
            for (int k = j; k < C; k++) {
                ch+= grid[i][k];
                sort(ch.begin(), ch.end());
                if (m.count(ch)) {
                    for (int f = j; f <= k; f++) {
                        cnt[i][f].insert(ch);
                    }
                }
            }
            /// move v
            ch = "";
            for (int k = i; k < L; k++) {
                ch+= grid[k][j];
                sort(ch.begin(), ch.end());
                if (m.count(ch)) {
                    for (int f = i; f <= k; f++) {
                        cnt[f][j].insert(ch);
                    }
                }
            }
            /// diag
            int di = i, dj = j;
            ch = "";
            while (true) {
                if (di == L || dj == C)
                    break;
                ch+= grid[di][dj];
                sort(ch.begin(), ch.end());
                if (m.count(ch)) {
                    for (int ii = i, jj = j; ii <= di && jj <= dj; ii++, jj++) {
                        cnt[ii][jj].insert(ch);
                    }
                }
                di++; dj++;
            }
            /// diag 2;
            di = i, dj = j;
            ch = "";
            while (true) {
                if (dj == -1 || di == L)
                    break;
                ch+= grid[di][dj];
                sort(ch.begin(), ch.end());
                if (m.count(ch)) {
                    for (int ii = i, jj = j; ii <= di && jj >= dj; ii++,jj--) {
                        cnt[ii][jj].insert(ch);
                    }
                }
                di++; dj--;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (cnt[i][j].size() > 1)
                ans++;
        }
    }
    cout << ans;
}