#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    string s = "codeforces";
    map<char, bool> m;
    for (char c : s)
        m[c] = true;
    while (T--) {
        char c; cin >> c;
        if (m[c]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
}