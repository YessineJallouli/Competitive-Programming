//
// Created by yessine on 01/08/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        if (a[0] == a[n-1]) {
            cout << "NO\n";
        }
        else if (a[n-1] == a[n-2]) {
            cout << "YES\n";
            cout << a[n-1] << ' ' << a[0] << ' ';
            for (int i = n-2; i > 0; i--) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
        else {
            cout << "YES\n";
            for (int i = n-1; i >= 0; i--) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
    }
}