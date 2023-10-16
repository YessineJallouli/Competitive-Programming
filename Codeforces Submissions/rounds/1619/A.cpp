#include <bits/stdc++.h>
using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();
        bool ans = true;
        if (n%2)
            ans = false;
        for (int i = 0; i < n/2 && ans; i++) {
            if (s[i] != s[i+n/2])
                ans = false;
        }
        if (ans) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}