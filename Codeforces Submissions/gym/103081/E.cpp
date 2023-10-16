    #include <bits/stdc++.h>
    #define ll long long
    #define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
    using namespace std;

    int main() {
        int n; cin >> n;
        int ans = INT_MAX;
        while (n--) {
            int a,b; cin >> a >> b;
            ans = min(ans, b/a);
        }
        cout << ans;
    }