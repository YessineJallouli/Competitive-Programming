#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    string s; cin >> s;
    int n = (int) s.size();
    string k = "cdhs";
    int ans = 0;
    do {
        map<char,int> m;
        for (int i = 0; i < 4; i++)
            m[k[i]] = i;
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = m[s[i]];
        }

        int dp[4];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++) {
            int c = a[i];
            int mx = 0;
            for (int j = 0; j <= c; j++) {
                mx = max(mx, dp[j]);
            }
            dp[c] = max(dp[c], mx+1);
            ans = max(ans, dp[c]);
        }

    } while (next_permutation(k.begin(), k.end()));
    cout << n-ans;
}