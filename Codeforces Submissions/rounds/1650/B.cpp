#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int l,r,a; cin >> l >> r >> a;
        int p = r-r%a-1;
        if (p < l)
            p = l;
        cout << max(p/a+p%a, r/a+r%a) << '\n';
    }
}