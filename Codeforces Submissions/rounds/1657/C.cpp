#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int operation = 0;
        int lastId = 0;
        bool can = true;
        for (int i = 0; i < n-1; i++) {
            if (can && ((s[i] == s[i+1] || s[i] == '('))) {
                operation++;
                i++;
                lastId = i+1;
                continue;
            }
            if (s[i] == ')') {
                can = false;
                for (int j = i+1; j < n; j++) {
                    if (s[j] == ')') {
                        i = j;
                        lastId = j + 1;
                        operation++;
                        can = true;
                        break;
                    }
                }
            }
        }
        cout << operation << ' ' << n-lastId << '\n';
    }
}