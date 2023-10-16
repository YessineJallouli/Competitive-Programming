#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("scoreboard.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        string ch; cin >> ch;
        set<pair<int,char>> s;
        for (int i = 0; i < 13; i++) {
            bool b = false;
            int x; cin >> x;
            for (char c : ch) {
                if (c == 'A'+i)
                    b = true;
            }
            if (! b) {
                s.insert({x,i+'A'});
            }
        }
        cout << (*s.rbegin()).second << '\n';
    }
}