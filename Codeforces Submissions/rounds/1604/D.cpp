#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int nb = 0;
        int x,y; cin >> x >> y;
        if (x > y) {
            cout << x+y << '\n';
            continue;
        }
        int X = y/x*x;
        bool ok = false;
        while (X > 0) {
            int n = (X+y)/2;
            if ((n%x) == (y%n)) {
                cout << n << '\n';
                ok = true;
                break;
            }
            X-= x;
        }
    }
}