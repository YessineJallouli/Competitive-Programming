#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        bool ans = false;
        string s;
        cin >> s;
        char c;
        cin >> c;
        for (int i = 0; i < s.size(); i+=2) {
            if (c == s[i])
                ans = true;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}