#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        n*= 2;
        string s[n+1];
        int nb[26];
        memset(nb, 0, sizeof nb);
        for (int i = 0; i < n+1; i++) {
            cin >> s[i];
            for (char c : s[i]) {
                nb[c-'a']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            //cout << nb[i] << ' ';
            if (nb[i]%2) {
                cout << char(i+'a') << '\n';
            }
        }
    }
}