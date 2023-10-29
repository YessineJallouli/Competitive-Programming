//100%
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    cin.ignore();
    string s[n];
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
        int nb[7];
        memset(nb, 0, sizeof nb);
        int mx = 0;
        for (char c : s[i]) {
            if (c >= 'a' && c <= 'g') {
                nb[c-'a']++;
                mx = max(mx, nb[c-'a']);
            }
        }
        for (int j = 0; j < 7; j++) {
            if (nb[j] == mx) {
                cout << char(j+'A') << '\n';
                break;
            }
        }
    }

}
