#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int mx = 'a';
        int mn = 'a';
        for (char c : s) {
            mx = max((int) c, mx);
        }
        cout << mx-mn+1 << '\n';
    }
}