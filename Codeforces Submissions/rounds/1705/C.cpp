#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n,c,q; cin >> n >> c >> q;
        string s; cin >> s;
        pair<long long ,long long> rg[c+1];
        rg[0] = {0,n-1};
        pair<ll,ll> cp[c+1];
        cp[0] = {0, n-1};
        for (ll i = 1; i <= c; i++) {
            ll a,b; cin >> a >> b;
            rg[i] = {rg[i-1].second+1, rg[i-1].second+b-a+1};
            cp[i] = {a-1, b-1};
        }
        while (q--) {
            ll k; cin >> k;
            k--;
            while (k >= n) {
                for (int i = 0; i <= c; i++) {
                    if (k >= rg[i].first && k <= rg[i].second) {
                        ll df = k-rg[i].first;
                        k = cp[i].first+df;
                    }
                }
            }
            cout << s[(k+n)%n] << '\n';
        }
    }
}