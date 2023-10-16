#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (j == 1 || j == i) {
                    cout << 1 << ' ';
                }
                else {
                    cout << 0 << ' ';
                }
            }
            cout << '\n';
        }
    }
}