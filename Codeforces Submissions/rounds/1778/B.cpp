#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m,d; cin >> n >> m >> d;
        int a[n];
        int b[m];
        int pos[n+1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i+1;
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int ans;
        bool ok = false;
        for (int i = 0; i < m-1; i++) {
            //cout << pos[b[i]] << ' ' << pos[b[i+1]] << '\n';
            if (pos[b[i]] > pos[b[i+1]])
                ok = true;
            if (pos[b[i+1]] > pos[b[i]]+d)
                ok = true;
        }
        if (ok)
            cout << 0 << '\n';
        else {
            ans = INT_MAX;
            for (int i = 0; i < m-1; i++) {
                int k1 = pos[b[i]];
                int k2 = pos[b[i+1]];
                ans = min(ans, k2-k1);
                if (d < n-1)
                    ans = min(ans, d-(k2-k1)+1);
            }
            cout << ans << '\n';
        }

    }
}