#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n],b[n],c[n];
        int p1[n+1];
        int p2[n+1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            p1[a[i]] = i;
            p2[b[i]] = i;
        }
        memset(c, 0, sizeof c);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (c[i] == 0)
                c[i] = x;
            if (a[i] == b[i]) {
                c[i] = a[i];
            }
            if (c[i] != 0) {
                if (c[i] == a[i]) {
                    int id = p1[b[i]];
                    while (c[id] == 0) {
                        c[id] = a[id];
                        id = p1[b[id]];
                    }
                }
                else if (c[i] == b[i]){
                    int id = p2[a[i]];
                    while (c[id] == 0) {
                        c[id] = b[id];
                        id = p2[a[id]];
                    }
                }

            }
        }
        ll ans = 1;
        int mod = 1e9+7;
        for (int i = 0; i < n; i++) {
            if (c[i] == 0) {
                int id = i;
                while (c[id] == 0) {
                    c[id] = a[id];
                    id = p1[b[id]];
                }
                ans = (ans*2)%mod;
            }
        }
        cout << ans << '\n';
    }
}