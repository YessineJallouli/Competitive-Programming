#include <bits/stdc++.h>
#define ll lo
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        bool ans = true;
        for (int i = 1; i < n-1; i++) {
            if (s[i] != 'W' && s[i+1] == 'W' && s[i-1] == 'W')
                ans = false;
        }
        if (n == 1 && s[0] != 'W')
            ans = false;
        if (n == 2 && s[0] == 'W' && s[1] != 'W')
            ans = false;
        if (n == 2 && s[0] != 'W' && s[1] == 'W')
            ans = false;
        int nbR = 0; int nbB = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (nbR == 0 && nbB != 0) {
                    ans = false;
                }
                if (nbB == 0 && nbR != 0)
                    ans = false;
                nbB = nbR = 0;
            }
            if (s[i] == 'R') {
                nbR++;
            }
            if (s[i] == 'B')
                nbB++;
        }
        if (nbR == 0 && nbB != 0) {
            ans = false;
        }
        if (nbB == 0 && nbR != 0)
            ans = false;
        cout << (ans ? "YES\n" : "NO\n");
    }
}