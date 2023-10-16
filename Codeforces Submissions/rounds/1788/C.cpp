//
// Created by yessine on 2/9/23.
//
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll sum = 2LL*n*(2LL*n+1)/2;
        ll k = (2*sum-1LL*n*n+n)/n;
        if (k%2) {
            cout << "NO\n";
            continue;
        }
        else {
            cout << "YES\n";
            int l = k/2;
            int d = l-1;
            for (int i = 1; i <= (n+1)/2; i++) {
                cout << i << ' ' << d+i-1 << '\n';
            }
            d = n+1;
            int nb = 0;
            for (int i = (n+1)/2+1; i <= n; i++) {
                cout << i << ' ' << nb+d << '\n';
                nb++;
            }
        }
    }
}