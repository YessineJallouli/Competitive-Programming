#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll lcm(ll a, ll b) {
    return a*b/__gcd(a,b);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        int nbR = 0;
        ll sc = a[0]*b[0];
        ll Lcm = b[0];
        for (int i = 0; i < n; i++) {
            sc = __gcd(sc, a[i]*b[i]);
            Lcm = lcm(b[i], Lcm);
            //cout << sc << ' ' << Lcm << '\n';
            if (sc%Lcm != 0) {
                nbR++;
                sc = a[i]*b[i];
                Lcm = b[i];
            }
        }
        cout << nbR+1 << '\n';
    }
}