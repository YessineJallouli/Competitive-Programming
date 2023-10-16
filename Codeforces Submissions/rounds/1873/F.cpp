#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll k;
int solve(vector<int> &v) {
    int n = (int) v.size();
    vector<ll> pr(n+1);
    pr[0] = 0;
    for (int i = 0; i < n; i++) {
        pr[i+1] = pr[i]+v[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int a = lower_bound(pr.begin(), pr.end(), pr[i]-k) - pr.begin();
        ans = max(ans, i-a);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n >> k;
        int a[n],h[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<int> v;
        v.push_back(a[0]);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (h[i-1]%h[i] == 0) {
                v.push_back(a[i]);
            }
            else {
                ans = max(ans, solve(v));
                v.clear();
                v.push_back(a[i]);
            }
        }
        ans = max(ans, solve(v));
        cout << ans << '\n';
    }
}