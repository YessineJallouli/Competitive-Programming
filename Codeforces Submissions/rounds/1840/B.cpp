//
// Created by yessine on 6/6/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        if (k > 30) {
            cout << n+1 << '\n';
        }
        else {
            cout << min(n+1, (1 << k)) << '\n';
        }
    }

}