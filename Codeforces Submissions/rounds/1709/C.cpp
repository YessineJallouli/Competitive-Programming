#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isRegular(string &s) {
    int nb = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '(') {
            nb++;
        }
        else {
            nb--;
        }
        if (nb < 0) {
            return false;
        }
    }
    return (nb == 0);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int) s.size();
        int nb = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                nb++;
        }
        if (nb == n/2) {
            cout << "YES\n";
            continue;
        }

        string ch = s;
        int nb1 = nb;
        bool first_time = true;
        for (int i = 0; i < n; i++) {
            if (ch[i] == '?' && nb1 == n/2-1 && first_time) {
                ch[i] = ')';
                first_time = false;
            }
            else if (ch[i] == '?' && nb1 == n/2-1 && ! first_time) {
                ch[i] = '(';
                nb1++;
            }
            else if (ch[i] == '?' && nb1 != n/2) {
                ch[i] = '(';
                nb1++;
            }
            else if (ch[i] == '?') {
                ch[i] = ')';
            }
        }
        if (isRegular(ch)) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}