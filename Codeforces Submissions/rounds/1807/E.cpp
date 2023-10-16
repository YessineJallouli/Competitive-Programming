#include <bits/stdc++.h>
using namespace std;


int ask(int l, int r) {
    int k = r-l+1;
    cout << "? " << k << ' ';
    for (int i = l; i <= r; i++) {
        cout << i << ' ';
    }
    cout << endl;
    int x; cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int pr[n+1];
        pr[0] = 0;
        for (int i = 0; i < n; i++) {
            pr[i+1] = pr[i] + a[i];
        }
        int l = 1, r = n;
        int ans = -1;
        while (l <= r) {
            int m = (l+r)/2;
            int k = ask(l, m);
            if (k == pr[m]-pr[l-1]) {
                l = m+1;
            }
            else {
                r = m-1;
                ans = m;
            }
        }
        cout << "! " << ans << endl;
    }
}