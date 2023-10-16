#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll a,c,b,d; cin >> a >> c >> b >> d;
        ll p1 = a*d;
        ll p2 = c*b;
        if (p1 == p2) {
            cout << 0 << '\n';
        }
        else if (p1 == 0 || p2 == 0 || p1%p2 == 0 || p2%p1 == 0) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }

    }

}