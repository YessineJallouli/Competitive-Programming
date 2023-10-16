#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        string s,t; cin >> s >> t;
        bool c1[26];
        memset(c1, false, sizeof c1);
        for (char c : s) {
            c1[c-'a'] = true;
        }
        bool ans = false;
        for (char c : t) {
            if (c1[c-'a'])
                ans = true;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}