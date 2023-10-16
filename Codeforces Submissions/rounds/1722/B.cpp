#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s1; cin >> s1;
        string s2; cin >> s2;
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'G')
                s1[i] = 'B';
            if (s2[i] == 'G')
                s2[i] = 'B';
        }
        if (s1 == s2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}