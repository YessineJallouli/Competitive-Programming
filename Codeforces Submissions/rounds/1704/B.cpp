#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,x; cin >> n >> x;
        int a[n];
        for (int i=  0; i <n; i++) {
            cin >> a[i];
        }
        int l = a[0]-x, r = a[0]+x;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int l1 = a[i]-x, r1 = a[i]+x;
            if (l1 > r || l > r1) {
                ans++;
                l = l1;
                r = r1;
                continue;
            }
            l = max(l, l1);
            r = min(r, r1);
        }
        cout << ans << '\n';
    }

}