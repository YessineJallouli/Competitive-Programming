//
// Created by yessine on 4/2/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; string s; cin >> n >> s;
        string t = s;
        sort(t.begin(), t.end());
        if (t == s) {
            cout << t << '\n';
            continue;
        }
        char mn = 'z';
        for (char c : s)
            mn = min(c, mn);
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == mn) {
                cout << char(mn);
                for (int j = 0; j < i; j++)
                    cout << char(s[j]);
                for (int j = i+1; j < n; j++)
                    cout << char(s[j]);
                cout << '\n';
                break;
            }
        }

    }
}