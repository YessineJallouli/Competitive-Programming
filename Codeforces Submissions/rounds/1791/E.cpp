#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        ll ans = 0;
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans+= abs(a[i]);
            b[i] = abs(a[i]);
        }
        sort(b, b+n);
        int nbN = 0;
        bool z = false;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0)
                nbN++;
            if (a[i] == 0)
                z = true;
        }
        if (nbN%2 == 0) {
            cout << ans << '\n';
        }
        else {
            cout << ans-2*b[0] << '\n';
        }
    }
}