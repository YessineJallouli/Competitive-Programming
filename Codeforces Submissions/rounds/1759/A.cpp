//
// Created by yessine on 11/18/22.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        map<char,char> next;
        next['Y'] = 'e';
        next['e'] = 's';
        next['s'] = 'Y';
        string s; cin >> s;
        bool ans = true;
        if (s.size() == 1) {
            if (s != "e" && s != "s" && s != "Y")
                ans = false;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != next[s[i-1]])
                ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}