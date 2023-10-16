#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        if (s == "cab" || s == "bca") {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}