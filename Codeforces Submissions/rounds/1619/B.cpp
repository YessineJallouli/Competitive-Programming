#include <bits/stdc++.h>
using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x = sqrt(n);
        int y = cbrt(n);
        int z = sqrt(cbrt(n));
        cout << x+y-z<< '\n';
    }
}