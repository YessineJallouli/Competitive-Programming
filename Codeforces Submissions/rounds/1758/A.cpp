#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        string ch = s;
        reverse(ch.begin(), ch.end());
        cout << s + ch << '\n';
    }
}