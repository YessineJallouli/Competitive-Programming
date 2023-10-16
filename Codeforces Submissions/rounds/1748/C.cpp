#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll pr = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                pr+= a[i];
                if (pr == 0) {
                    ans++;
                }
            }
            else {
                pr = 0;
                int id = i+1;
                map<ll,int> nb;
                nb[0] = 1;
                int mx = 1;
                while (id != n && a[id] != 0) {
                    pr+= a[id];
                    nb[pr]++;
                    mx = max(mx, nb[pr]);
                    id++;
                }
                ans+= mx;
                i = id-1;
            }
        }
        cout << ans << '\n';
    }
}