//
// Created by yessine on 11/18/22.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,s; cin >> n >> s;
        int b[n];
        int mx = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sum-= b[i];
            mx = max(mx, b[i]);
        }
        sum += mx*(mx+1)/2;
        while (sum < s) {
            mx++;
            sum+= mx;
        }
        cout << ((sum == s) ? "YES\n" : "NO\n");
    }
}