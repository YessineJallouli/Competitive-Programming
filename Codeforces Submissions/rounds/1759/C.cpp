//
// Created by yessine on 11/18/22.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int l,r,x; cin >> l >> r >> x;
        int a,b; cin >> a >> b;
        if (a == b)
            cout << 0 << '\n';
        else if (abs(a-b) >= x) {
            cout << 1 << '\n';
        }
        else {
            if (a < b) {
                int df = b-a;
                if (a+x+df <= r) {
                    cout << 2 << '\n';
                }
                else if (a-x >= l) {
                    cout << 2 << '\n';
                }
                else if (r-b < x && b-l < x)
                    cout << -1 << '\n';
                else if (r-a < x && a-l < x)
                    cout << -1 << '\n';
                else
                    cout << 3 << '\n';
            }
            else {
                int df = a-b;
                if (a-x-df >= l) {
                    cout << 2 << '\n';
                }
                else if (a+x <= r) {
                    cout << 2 << '\n';
                }
                else if (r-b < x && b-l < x)
                    cout << -1 << '\n';
                else if (r-a < x && a-l < x)
                    cout << -1 << '\n';
                else
                    cout << 3 << '\n';
            }
        }
    }
}