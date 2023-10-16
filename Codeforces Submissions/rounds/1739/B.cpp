#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int d[n];
        int s = 0;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            cin >> d[i];
            if (d[i] == 0)
                continue;
            if (d[i] <= s)
                ans = false;
            s+= d[i];
        }
        if (ans) {
            int s = 0;
            for (int i = 0; i < n; i++) {
                s+= d[i];
                cout << s << ' ';
            }
            cout << '\n';
        }
        else {
            cout << -1 << '\n';
        }

    }
}