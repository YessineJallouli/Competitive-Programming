#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int x,y; x = y = 0;
        bool ans = false;
        for (char c : s) {
            if (c == 'U')
                y++;
            if (c == 'D')
                y--;
            if (c == 'R')
                x++;
            if (c == 'L')
                x--;
            if (x == 1 && y == 1)
                ans = true;
//            cout << x << ' ' << y << '\n';
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}