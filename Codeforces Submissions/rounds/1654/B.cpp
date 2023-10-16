#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();
        int nb[26];
        memset(nb, 0, sizeof nb);
        for (int i = 0; i < n; i++) {
            nb[s[i]-'a']++;
        }
        for (int i = 0; i < n; i++) {
            nb[s[i]-'a']--;
            if (nb[s[i] - 'a'] == 0) {
                for (int j = i; j < n; j++)
                    cout << s[j];
                break;
            }
        }
        cout << '\n';
    }
}