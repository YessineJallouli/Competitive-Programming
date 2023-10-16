//
// Created by yessine on 2/9/23.
//
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main() {

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        int nb = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 2)
                nb++;
        }
        if (nb%2) {
            cout << -1 << '\n';
        }
        else {
            if (nb == 0) {
                cout << 1 << '\n';
            }
            else {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i] == 2)
                        cnt++;
                    if (cnt == nb/2) {
                        cout << i+1 << '\n';
                        break;
                    }
                }
            }
        }
    }
}