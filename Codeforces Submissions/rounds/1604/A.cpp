#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans=  0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            ans=  max(ans, x-i-1);
        }
        cout << ans << '\n';
    }
}