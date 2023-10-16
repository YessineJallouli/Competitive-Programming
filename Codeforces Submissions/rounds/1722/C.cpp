#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s[3][n];
        map<string,int> nb;
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < n; i++) {
                cin >> s[j][i];
                nb[s[j][i]]++;
            }
        }
        int score[3];
        memset(score, 0, sizeof score);
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < n; i++) {
                int x = nb[s[j][i]];
                if (x == 1)
                    score[j]+= 3;
                else if (x == 2)
                    score[j]+= 1;
            }
        }
        for (int i = 0; i < 3; i++)
            cout << score[i] << ' ';
        cout << '\n';
    }
}