#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int h,m; cin >> h >> m;
        int slp = h*60+m;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int a,b; cin >> a >> b;
            int mnt = a*60+b;
            if (mnt >= slp) {
                ans = min(ans, mnt-slp);
            }
            else {
                ans = min(ans, 24*60-(slp-mnt));
            }
        }
        cout << ans/60 << ' ' << ans%60 << '\n';

    }
    return 0;
}