#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int nb = 0;
        for (int i = 0; i < 3; i++)
            nb+= s[i]-s[i+3];
        cout << (nb ? "NO\n" : "YES\n");
    }
}