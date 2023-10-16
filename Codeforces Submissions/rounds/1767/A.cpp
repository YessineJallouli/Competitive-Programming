//
// Created by yessine on 12/16/22.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int a1,a2,a3,b1,b2,b3; cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
        int nb = 0;
        if (a1 == a2 || a1 == a3 || a2 == a3) {
            nb++;
        }
        if (b1 == b2 || b1 == b3 || b2 == b3) {
            nb++;
        }
        if (nb == 2) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}