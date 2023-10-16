#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1001;
int mxPos[N];

int main() {
    int T; cin >> T;
    while (T--) {
        int n,q; cin >> n >> q;
        int a[n];
        int mx[n];
        ll s[n+1];
        s[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        mx[0] = a[0];
        for (int i = 0; i < n; i++) {
            s[i+1] = s[i] + a[i];
            if (i)
                mx[i] = max(mx[i-1], a[i]);
        }
        while (q--) {
            int h; cin >> h;
            int k = upper_bound(mx, mx+n, h) - mx;
            cout << s[k] << ' ';
        }
        cout << '\n';
    }
}