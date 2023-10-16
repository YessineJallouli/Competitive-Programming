#include <bits/stdc++.h>
using namespace std;

bool isSquare(int a) {
    int x = sqrt(a);
    return (x*x == a);
}

int main() {
    int T; cin >> T;
    while (T--) {
        int a,b; cin >> a >> b;
        if (a+b == 0) {
            cout << 0 << '\n';
        }
        else {
            int d = a*a+b*b;
            if (isSquare(d)) {
                cout << 1 << '\n';
            }
            else
                cout << 2 << '\n';
        }
    }
}