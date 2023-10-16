#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int x; cin >> x;
    return x;
}

int mx = 1e9;

int main() {
    int T; cin >> T;
    while (T--) {
        int p = 1;
        int minus = 0;
        int x = 0;
        int nb = 0;
        while (p < mx) {
            if (p == 1) {
                int r = ask(1,3);
                if (r%2 == 0) {
                    minus = 1;
                    x++;
                }
            }
            else {
                int r = ask(p-minus, p*2+p-minus);
                if (r%(2*p) == 0) {
                    minus+= p;
                    x+= p;
                }
            }
            p*= 2;
            nb++;
        }
        cout << "! " << x << endl;
    }
}