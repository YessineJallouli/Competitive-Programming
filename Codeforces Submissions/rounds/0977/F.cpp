#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,int> dp;
    int n; cin >> n;
    int ans = 0;
    int id = -1;
    int a[n];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        dp[x] = max(dp[x-1]+1, dp[x]);
        if (ans < dp[x]) {
            ans = max(dp[x], ans);
            id = x;
        }
    }
    cout << ans << endl;
    vector<int> v;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == id) {
            id--;
            v.push_back(i+1);
        }
    }
    reverse(v.begin(), v.end());
    for (int i : v)
        cout << i << ' ';
}