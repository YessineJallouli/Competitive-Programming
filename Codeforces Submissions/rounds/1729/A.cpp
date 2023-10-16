#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int a,b,c; cin >> a >> b >> c;
        if (abs(a-1) < abs(b-c) + abs(c-1)) {
            cout << 1 << '\n';
        }
        else if (abs(a-1) > abs(b-c) + abs(c-1))
            cout << 2 << '\n';
        else
            cout << 3 << '\n';
    }
}