#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<ll,int> x;
        map<ll,int> y;
        map<ll,int> d;
        map<ll,int> o;
        for (int i = 0; i < n; i++) {
            ll a,b; cin >> a >> b;
            x[a]++,
            y[b]++;
            d[a-b]++;
            o[a+b]++;
        }
        ll ans = 0;
        for (auto [a,b] : x) {
            ans+= 1LL*(b)*(b-1);
        }
        for (auto [a,b] : y) {
            ans+= 1LL*(b)*(b-1);
        }
        for (auto [a,b] : d) {
            ans += 1LL * (b) * (b - 1);
        }
        for (auto [a,b] : o)
            ans+= 1LL*(b)*(b-1);
        cout << ans << '\n';
    }
}