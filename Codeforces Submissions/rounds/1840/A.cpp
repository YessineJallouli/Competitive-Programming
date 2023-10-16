//
// Created by yessine on 6/6/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (s[j] == s[i]) {
                    i = j;
                    cout << s[i];
                    break;
                }
            }
        }
        cout << '\n';
    }

}