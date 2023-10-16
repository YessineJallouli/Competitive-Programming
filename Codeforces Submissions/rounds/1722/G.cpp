#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n%4 == 0) {
            for (int i = 0; i < n/2; i++) {
                cout << i << ' ' << i+(1 << 30) << ' ';
            }
            cout << '\n';
        }
        else if (n%4 == 1) {
            for (int i = 1; i <= n/2; i++) {
                cout << i << ' ' << i+(1<<30) << ' ';
            }
            cout << 0 << '\n';
        }
        else if (n%4 == 2) {
            cout << 1 << ' ' << 3 << ' ' << 2 << ' ' << (1<<30) << ' ';
            n-= 4;
            for (int i = 0; i < n/2; i++) {
                cout << i+4 << ' ' << i+4+(1<<30) << ' ';
            }
            cout << '\n';
        }
        else {
            cout << (1<<30) << ' ';
            for (int i =1; i <= n/2; i++) {
                cout << i << ' ' << i+(1<<30) << ' ';
            }
            cout << '\n';
        }
    }
}