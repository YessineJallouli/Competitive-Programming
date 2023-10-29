//80%
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll v0,v1,v2; cin >> v0 >> v1 >> v2;
        ll v6 = 1;
        ll v9 = v0 + v1;
        ll v10 = 0;
        for (int v12 = 1; v12 <= v2; v12++) {
            v10+= v0;
            ll v13 = v10;
            v13 = v13%v1;
            if (2*v13 > v1)
                v13 = v1-v13;
           
            ll v17 = v6*v13-v12*v9;
            if (v17 < 0) {
                v6 = v12;
                v9 = v13;
            }
        }
        cout << v6 << '\n';
    }
}
