#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int a[n];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt+= a[i];
        }
        int s = 0;
        int nb[n+1];
        memset(nb, 0, sizeof nb);
        pair<int,int> fr[m];
        for (int i = 0; i < m; i++) {
            int x,y; cin >> x >> y;
            fr[i] = {x,y};
            nb[x-1]++;
            nb[y-1]++;
        }
        if (m%2 == 0) {
            cout << 0 << '\n';
        }
        else {
            int mn = INT_MAX;
            for (int i = 0; i < m; i++) {
                auto [x,y] = fr[i];
                x--; y--;
                if (nb[x]%2 == 1) {
                    mn = min(mn, a[x]);
                }
                if (nb[y]%2 == 1) {
                    mn = min(mn, a[y]);
                }
                if (nb[x]%2 == 0 && nb[y]%2 == 0) {
                    mn = min(mn, a[x]+a[y]);
                }
            }
            cout << mn << '\n';
        }

    }

}