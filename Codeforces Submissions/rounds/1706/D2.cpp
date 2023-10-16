#include <bits/stdc++.h>
#define ll long long
using namespace std;

int F(int a, int b) {
    int k1 = a/(b+1)+1;
    return k1;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (k > a[n-1]) {
            cout << 0 << '\n';
            continue;
        }
        int res = a[n-1];
        for (int mx = 1; mx <= 100101; mx++) {
            if (F(a[n-1],mx) > k)
                continue;

            int mn = a[0];
            int mx1 = 0;

            int target = mx;
            int i = upper_bound(a.begin(), a.end(), target) - a.begin();

            if (i != n && i != 0) {
                mx1 = a[i-1];
            }
            else if (i != 0)
                mx1 = a[n-1];

            while (i != n) {
                int val = a[i];
                int k1 = val/(mx+1)+1;

                if (F(a[n-1],mx) == k1) {
                    mn = min(mn,val/k1);
                    mx1 = max(mx1, a[n-1]/k1);
                    if (res > mx1-mn) {
                        res = mx1-mn;
                    }
                    break;
                }
                int d = i, f = n-1;
                int ans = -1;
                while (d <= f) {
                    int m = (d+f)/2;
                    if (F(a[m],mx) == k1) {
                        ans = m;
                        d = m+1;
                    }
                    else
                        f = m-1;
                }
                mn = min(mn, a[i]/k1);
                mx1 = max(mx1, a[ans]/k1);
                i = ans+1;
            }
            if (res > mx1-mn)
                res = mx1-mn;
        }
        cout << res << '\n';
    }
}