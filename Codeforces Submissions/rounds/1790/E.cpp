#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while (T--) {
        set<int> s;
        int x; cin >> x;
        if (x%2) {
            cout << -1 << '\n';
            continue;
        }
        int a = x/2;
        int b = x+x/2;
        int xr = a^b;
        if (xr == x) {
            cout << a << ' ' << b << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}