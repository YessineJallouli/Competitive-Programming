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
        int n,k,q; cin >> n >> k >> q;
        vector<int> blocks;
        int a[n];
        int curr = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > q) {
                if (curr >= k) {
                   ll diff = curr-k+1;
                   ans+= diff * (diff+1)/2;
                }
                curr = 0;
            }
            else
                curr++;
        }
        if (curr >= k) {
            ll diff = curr-k+1;
            ans += diff * (diff + 1) / 2;
        }
        cout << ans << '\n';
    }

}