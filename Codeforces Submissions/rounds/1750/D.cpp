// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

ll m;

ll mod = 998244353;

ll nb(ll k) {
    if (k == 0)
        return 0;
    return m/k;
}

int pcm(ll a, ll b) {
    return (a*b)/__gcd(a,b);
}

int main() {
    SaveTime
    ll T; cin >> T;
    while (T--) {
        ll n;
        cin >> n >> m;
        ll a[n];
        bool ans = true;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            if (i && a[i-1]%a[i] != 0)
                ans = false;
        }
        if (!ans) {
            cout << 0 << '\n';
            continue;
        }
        set<ll> divisors;
        for (ll i = 1; i*i <= a[0]; i++) {
            if (a[0]%i == 0) {
                divisors.insert(i);
                divisors.insert(a[0]/i);
            }
        }
        ll res = 1;
        for (ll i = 1; i < n; i++) {
            if (a[i] == a[i-1]) {
                res = (res*nb(a[i]))%mod;
                continue;
            }
            vector<ll> v;
            for (ll d : divisors) {
                if (a[i-1]%d == 0 && d != a[i] && d%a[i] == 0)
                    v.push_back(d);
            }
            vector<ll> r;
            for (ll j = 0; j < v.size(); j++) {
                bool ins = true;
                for (ll k = j-1; k >= 0; k--) {
                    if (v[j]%v[k] == 0)
                        ins = false;
                }
                if (ins)
                    r.push_back(v[j]);
            }
            ll sz = (ll) r.size();
            ll contribution = 0;
            for (ll j = 0; j < (1 << sz); j++) {
                ll cnt = 0;
                int p = 1;
                for (ll bit = 0; bit < sz; bit++) {
                    if (j & (1 << bit)) {
                        cnt++;
                        p = pcm(p, r[bit]);
                    }
                }
                //cout << p << ' ' << cnt << '\n';
                if (cnt%2) {
                    contribution+= nb(p);
                }
                else if (cnt != 0)
                    contribution-= nb(p);
            }

            contribution = (nb(a[i])-contribution)%mod;
            res = (res*contribution)%mod;
        }
        cout << res << '\n';
    }
}