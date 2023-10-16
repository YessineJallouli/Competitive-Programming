#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        bool b1 = false;
        bool b2 = false;
        bool b3 = false;
        bool b4 = false;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == 'a' && s[i+1] == 'a')
                b1 = true;
            if (i < n-2) {
                if (s[i] == 'a' && s[i+2] == 'a') {
                    b2 = true;
                }
            }
            if (i < n-3) {
                if (s[i] == 'a' && s[i+3] == 'a') {
                    string ch = "";
                    ch+= s[i+1];
                    ch+= s[i+2];
                    sort(ch.begin(), ch.end());
                    if (ch == "bc")
                        b3 = true;
                }
            }
            if (i < n-6) {
                if (s[i] == 'a' && s[i+3] == 'a' && s[i+6] == 'a') {
                    string ch = "";
                    ch+= s[i+1];
                    ch+= s[i+2];
                    string ch1 = "";
                    ch1+= s[i+4];
                    ch1+= s[i+5];
                    if (ch == "bb" && ch1 == "cc") {
                        b4 = true;
                    }
                    if (ch == "cc" && ch1 == "bb")
                        b4 = true;
                }
            }
        }
        if (b1) {
            cout << 2 << '\n';
            continue;
        }
        if (b2) {
            cout << 3 << '\n';
            continue;
        }
        if (b3) {
            cout << 4 << '\n';
            continue;
        }
        if (b4) {
            cout << 7 << '\n';
            continue;
        }
        cout << -1 << '\n';
    }
}