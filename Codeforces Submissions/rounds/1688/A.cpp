#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        if (x == 1) {
            cout << 3 << '\n';
            continue;
        }
        int p = 1;
        int X = x;
        while (x%2 == 0) {
            x/= 2;
            p*= 2;
        }
        if (x == 1) {
            cout << X+1 << '\n';
        }
        else {
            cout << p << '\n';
        }
    }
}