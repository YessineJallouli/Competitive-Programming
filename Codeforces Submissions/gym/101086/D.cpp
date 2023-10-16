#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    string ch = "AHIMOTUVWXY";
    map<char,char> next;
    for (int i = 0; i < 10; i++) {
        next[ch[i]] = ch[i+1];
    }

    long long pow11[10];
    pow11[0] = 1;
    for (int i = 1; i < 10; i++) {
        pow11[i] = pow11[i-1]*11;
    }

    while (T--) {
        long long k; string s;
        cin >> k >> s;
        reverse(s.begin(), s.end());
        while (k) {
            int l = (int) s.size();
            for (int i = min(l-1,9); i>= 0; i--) {
                while (s[i] != 'Y') {
                    long long nb = pow11[i];
                    if (nb <= k) {
                        k-= nb;
                        s[i] = next[s[i]];
                    }
                    else
                        break;
                }
            }
            if (k) {
                k--;
                int i = 0;
                while (s[i] == 'Y' && i != l) {
                    s[i++] = 'A';
                }
                if (i == l) {
                    s+= 'A';
                }
                else
                    s[i] = next[s[i]];
            }
        }
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}