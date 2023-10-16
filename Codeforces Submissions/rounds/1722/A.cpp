#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s = "Timur";
        sort(s.begin(), s.end());
        int n; cin >> n;
        string ch; cin >> ch;
        sort(ch.begin(), ch.end());
        if (ch == s) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}