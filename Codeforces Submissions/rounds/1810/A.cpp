//
// Created by yessine on 3/31/23.
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
        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (a[i] <= i+1)
                ans = true;
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}