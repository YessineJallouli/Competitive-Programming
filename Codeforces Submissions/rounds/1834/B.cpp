//
// Created by yessine on 6/24/23.
//

#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        string L,R; cin >> L >> R;
        while (L.size() != R.size()) {
            L = '0' + L;
        }
        int n = (int) L.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (L[i] != R[i]) {
                if (i == n-1) {
                    ans+= R[i]-L[i];
                }
                else {
                    for (int j = i+1; j < n; j++)
                        ans+= 9;
                    ans+= R[i]-L[i];
                }
                break;
            }
        }
        cout << ans << '\n';
    }
}