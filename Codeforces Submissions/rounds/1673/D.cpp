#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        long long b,q,y; cin >> b >> q >> y;
        long long c,r,z; cin >> c >> r >> z;
        long long mx2 = 1LL*c+1LL*r*(z-1);
        long long mx1 = 1LL*b+1LL*q*(y-1);
        if (z > y || r%q != 0 || mx2 > mx1 || c < b || ((b-c)%q != 0)) {
            cout << 0 << '\n';
            continue;
        }
        if (mx2+r > mx1 || c-r < b) {
            cout << -1 << '\n';
            continue;
        }
        set<long long> good_divisor;
        for (long long i = 1; i*i <= r; i++) {
            if (r%i == 0) {
                long long d1 = i;
                long long d2 = r/i;
                if ((d1*q) /__gcd(d1,q) == r) {
                    good_divisor.insert(d1);
                }
                if ((d2*q) /__gcd(d2,q) == r) {
                    good_divisor.insert(d2);
                }
            }
        }
        long long ans = 0;
        for (long long i : good_divisor) {
            long long nbChoice1 = r/i;
            ans+= nbChoice1* nbChoice1%mod;
            ans%=mod;
        }
        cout << ans << '\n';
    }
}