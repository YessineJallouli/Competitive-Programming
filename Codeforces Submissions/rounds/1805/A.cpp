//
// Created by yessine on 4/2/23.
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
        int x = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            x^= a[i];
        }
        if (x == 0 || n%2 == 1) {
            cout << x << '\n';
        }
        else {
            cout << -1 << '\n';
        }

    }
}