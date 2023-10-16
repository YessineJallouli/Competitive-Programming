#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        if (k%2 == 1) {
            cout << "YES\n";
            for (int i = 1; i <= n; i+= 2) {
                cout << i << ' ' << i+1 << '\n';
            }
        }
        else if (k % 4 == 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            for (int i = 4; i <= n; i+= 4) {
                cout << i-1 << ' ' << i << '\n';
            }
            for (int i = 2; i <= n; i+= 4) {
                cout << i << ' ' << i-1 << '\n';
            }
        }
    }
}