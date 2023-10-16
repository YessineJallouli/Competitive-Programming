//
// Created by yessine on 01/08/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int first = 1;
        int last = n*n;
        int ans[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (n%2 == 0) {
                    if (j % 2) {
                        ans[i][j] = last;
                        last--;
                    } else {
                        ans[i][j] = first;
                        first++;
                    }
                }
                else {
                    if ((i+j)%2) {
                        ans[i][j] = last;
                        last--;
                    }
                    else {
                        ans[i][j] = first;
                        first++;
                    }
                }
            }
        }
        if (n%2 == 0) {
            for (int i = 1; i < n; i+=2) {
                reverse(ans[i], ans[i]+n);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}