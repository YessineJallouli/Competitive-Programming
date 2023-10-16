#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        if (n > 2) {
            cout << "NO\n";
        }
        else if (n == 1) {
            cout << "YES\n";
        }
        else {
            if (s[0] == s[1]) {
                cout << "NO\n";
            }
            else
                cout << "YES\n";
        }
    }
}