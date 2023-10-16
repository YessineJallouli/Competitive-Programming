
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s[n];
        map<string, bool> m;
        bool ans = false;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            m[s[i]] = true;
        }
        for (int i = 0; i < n; i++) {
            string ch = s[i];
            reverse(ch.begin(), ch.end());
            if (m[ch])
                ans = true;
        }
        for (int i = 0; i < n; i++)
        bool ans = true;
        map<string, bool> first2;
        map<string, bool> two;
        for (int i = 0; i < n; i++) {
            if (s[i].size() == 2) {
                if (first2[s[i]])
                    ans = true;
                string ch = s[i];
                reverse(ch.begin(), ch.end());
                two[ch] = true;
            }
            if (s[i].size() == 3) {
                string ch = "";
                ch+= s[i][1];
                ch+= s[i][2];
                if (two[ch])
                    ans = true;
            }
            if (s[i].size() == 3) {
                string ch = s[i].substr(0,2);
                reverse(ch.begin(), ch.end());
                first2[ch] = true;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}