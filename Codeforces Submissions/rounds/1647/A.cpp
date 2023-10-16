#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n%3 == 0) {
            for (int i = 0; i < n; i+= 3) {
                cout << "21";
            }
            cout << '\n';
        }
        else if (n%3 == 1) {
            cout << 1;
            for (int i = 3; i < n; i+= 3) {
                cout << "21";
            }
            cout << '\n';
        }
        else {
            cout << 2;
            for (int i = 3; i < n; i+= 3) {
                cout << "12";
            }
            cout << '\n';
        }
    }
}