#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

/// Global variables

ll mod = 1e9+7;

ll prime = 31;

const ll N = 2e6+7;
deque<ll> a(N), b(N);

ll hsh(deque<ll> &d) {
    ll n = (ll) d.size();
    ll res = 0;
    ll p = 1;
    for (ll i = 0; i < n; i++) {
        ll k = (d[i]*p)%mod;
        res = (res+k)%mod;
        p = (p*prime)%mod;
    }
    return res;
}


long long fast_pow(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = (ans*a)%mod;
        a = (a*a)%mod;
        b/= 2;
    }
    return ans;
}
long long modinv(long long a) {
    return fast_pow(a, mod-2);
}

void solve() {
    ll n; cin >> n;
    a.resize(2*n);
    b.resize(2*n);
    for (ll i = 0; i < 2*n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    reverse(b.begin(), b.end());
    ll h1 = hsh(a);
    ll h2 = hsh(b);
    ll k = modinv(prime);
    for (ll i = 0; i < 2*n; i++) {
        if (h1 == h2) {
            // try i
            bool ok = true;
            for (ll j = 0; j < n/2; j++) {
                if (a[j] >= a[j+n]) {
                    ok = false;
                }
            }
            if (ok) {
                cout << i << '\n';
                return;
            }
            for (ll j = 0; j < n; j++) {
                ll kk = a[0];
                a.pop_front();
                a.push_back(kk);
            }
            // try i+n
            ok = true;
            for (ll j = 0; j < n/2; j++) {
                if (a[j] >= a[j+n])
                    ok = false;
            }
            if (ok) {
                cout << i+n << '\n';
                return;
            }
            cout << -1 << '\n';
            return;
        }
        // hash1
        h1 = (h1-a[0]+mod)%mod;
        h1 = (h1*k)%mod;
        ll pw = fast_pow(prime, 2*n-1);
        h1 = (h1+ (pw*a[0])%mod)%mod;

        h2 = (h2-(a[0]*pw)%mod+mod)%mod;
        h2 = (h2*prime)%mod;
        h2 = (h2+a[0])%mod;
        ll kk = a[0];
        a.pop_front();
        a.push_back(kk);
    }
    cout << -1 << '\n';
}

int main() {
    SaveTime
    freopen("meta_game_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll T; cin >> T;
    for (ll ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        solve();
    }
}