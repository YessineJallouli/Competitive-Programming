#include <bits/stdc++.h>
#define ll long long
using namespace std;



void dfs(int n) {

}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> tree(n);

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < min(n, i+300); j++) {
                if ((a[i]^j) < (a[j]^i)) {
                    tree[j].push_back(i);
                }
            }
        }
        int dp[n];
        memset(dp, 0, sizeof dp);

        for (int i = 0; i < n; i++) {
            for (int j : tree[i]) {
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, dp[i]);
        }
        cout << mx+1 << '\n';

    }
}