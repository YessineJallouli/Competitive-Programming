//
// Created by Yessine on 7/8/22.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        int s = a+b+c+d;
        if (s == 0) {
            cout << 0 << '\n';
        }
        else if (s == 4) {
            cout << 2 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }
}