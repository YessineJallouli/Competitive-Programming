#include <bits/stdc++.h>
#define ll unsigned long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main() {
    SaveTime
    string s; cin >> s;
    if (s.size() == 1) {
        if (s[0] == '0' || s[0] == 'X' || s[0] == '_')
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    int ans = 0;
    bool nonzero = true;
    for (int x = 0; x <= 9; x++) {
        string ch = s;
        for (int i = 0; i < s.size(); i++) {
            if (ch[i] == 'X') {
                ch[i] = x + '0';
                nonzero = false;
            }
        }
        reverse(ch.begin(), ch.end());
        if (ch.back() == '0')
            continue;
        int nb = 1;
        if (ch[0] == '_' && ch[1] == '_') {
            if (s.size() == 2)
                nb = 3;
            else
                nb = 4;
        }
        else if (ch[0] == '_') {
            if (ch[1] != '0' && ch[1] != '2' && ch[1] != '5' && ch[1] != '7')
                nb = 0;
            else
                nb = 1;
        }
        else if (ch[1] == '_') {
            if (ch[0] != '0' && ch[0] != '5')
                nb = 0;
            else {
                if (ch[0] == '0' && ch.size() == 2)
                    nb = 1;
                else
                    nb = 2;
            }
        }
        else {
            int res = 0;
            res+=(ch[0]-'0') + 10*(ch[1]-'0');
            if (res%25 != 0)
                continue;
        }
        for (int i = 2; i < s.size(); i++) {
            if (ch[i] == '_') {
                if (i == s.size()-1)
                    nb*= 9;
                else
                    nb*= 10;
            }
        }
        ans+= nb;
        if (nonzero)
            break;
    }
    cout << ans;
}