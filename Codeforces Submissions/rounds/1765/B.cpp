#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        bool b = true;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (b) {
                b = false;
                continue;
            }
            else {
                if (i == n-1)
                    ans = false;
                else if (s[i] != s[i+1])
                    ans = false;
                i++;
                b = true;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}