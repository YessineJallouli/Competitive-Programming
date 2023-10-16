#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 998244353;

int main() {
    ll n,m; cin >> n >> m;
    ll all = 0;
    ll pw = 1;
    ll M = m%mod;
    for (int i = 1; i <= n; i++) {
        pw = (pw*M)%mod;
        all = (all + pw)%mod;
    }
    ll ans = all;
    ll curr = 1;

    /// first element can be anything
    ll oneRemoval = m%mod;

    ll mins = m%mod;
    for (ll i = 2; i <= n; i++) {
        if (__gcd(i, curr) == 1)
            curr = curr*i;
        if (curr > m)
            break;
        ll nbComb = (m/curr)%mod;
        oneRemoval = (oneRemoval*nbComb)%mod;
        mins = (mins + oneRemoval)%mod;

    }
    cout << (ans-mins+mod)%mod << '\n';
}