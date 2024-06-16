#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 998244353;
const int mx = 2e5+7;

long long fact[mx];
long long invfact[mx];

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

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < mx; i++)
        fact[i] = fact[i-1] * i % mod;
    for (int i = 0; i < mx; i++)
        invfact[i] = modinv(fact[i]);
}

long long C(int n, int k) {
    if (k > n)
        return 0;
    return fact[n] * invfact[n-k] % mod * invfact[k] % mod;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    precompute();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans + (C(n,i) * fact[i])%mod)%mod;
        }
        cout << ans << '\n';
    }
}
