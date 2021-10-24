#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        int goal = (1<<m)-1;
        int ans[goal+1];
        int a[n];
        memset(a, 0, sizeof a);
        memset(ans, 0, sizeof ans);
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            int p = 1;
            for (int j = 0; j < m; j++) {
                if (s[j] == 'y') {
                    a[i]+= p;
                }
                p*= 2;
            }
        }
        for (int i = 0; i < (1<<m); i++) {
            for (int j = 0; j < n; j++) {
                int h = i|a[j];
                if (h == goal)
                    ans[i]++;
            }
            //cout << i << ' ' << ans[i] << '\n';
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                //cout << a[i] << ' ' << a[j] << '\n';
                int x = a[i]|a[j];
                //cout << x << '\n';
                res+= ans[x];
                int r = x|a[i];
                if (r == goal)
                    res--;
                int k = x|a[j];
                if (k == goal)
                    res--;
            }
        }
        cout << res/3 << '\n';
    }
}
