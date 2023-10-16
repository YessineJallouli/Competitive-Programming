//
// Created by yessine on 4/9/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n%2 == 1) {
            cout << "YES\n";
            continue;
        }
        if (n == 2) {
            if (a[0] > a[1]) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
            continue;
        }
        for (int i = n-2; i >= 1; i--) {
            ll df = a[n-1]-a[i];
            a[i]+= df;
            a[i-1]+= df;
        }
        bool ans = true;
        for (int i = 0; i < n-1; i++) {
            if (a[i] > a[i+1])
                ans = false;
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}