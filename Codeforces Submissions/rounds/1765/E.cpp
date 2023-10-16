#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n,a,b; cin >> n >> a >> b;
        if (a > b) {
            cout << 1 << '\n';
        }
        else {
            cout << (n+a-1)/a << '\n';
        }
    }
}