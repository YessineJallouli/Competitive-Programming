#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int,int> m;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x]++;
            mx = max(mx, m[x]);
        }
        int ans = n-mx;
        int num_cpy = 0;
        while (mx < n) {
            mx*= 2;
            num_cpy++;
        }
        cout << ans+num_cpy << '\n';
    }
}