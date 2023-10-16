#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        if (s[0] == s[3]) {
            cout << -1 << '\n';
        }
        else if (s[0] == s[2] || s[1] == s[3]) {
            cout << 6 << '\n';
        }
        else {
            cout << 4 << '\n';
        }
    }
}