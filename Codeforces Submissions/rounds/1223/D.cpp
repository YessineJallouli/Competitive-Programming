#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int a[n];
        int first_occ[n+1];
        int last_occ[n+1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            last_occ[a[i]] = i;
        }
        for (int i = n-1; i >= 0; i--)
            first_occ[a[i]] = i;
        sort(a, a+n);
        int dp[n+1];
        memset(dp, 0, sizeof dp);
        int distinct_elements = 1;
        int mx_fix = 1;
        dp[a[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1])
                continue;
            distinct_elements++;
            int r1 = last_occ[a[i-1]];
            int l2 = first_occ[a[i]];
            if (l2 > r1) {
                dp[a[i]] = dp[a[i-1]]+1;
                mx_fix = max(mx_fix, dp[a[i]]);
            }
            else {
                dp[a[i]] = 1;
            }
        }
        cout << distinct_elements-mx_fix << '\n';
    }
}