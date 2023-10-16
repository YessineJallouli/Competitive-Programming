#include <bits/stdc++.h>
#define ll long long
using namespace std;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int mx = 5e4+7;

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

long long C(int n, int k) {
    if (k > n)
        return 0;
    return fact[n] * invfact[n-k] % mod * invfact[k] % mod;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < mx; i++)
        fact[i] = fact[i-1] * i % mod;
    for (int i = 0; i < mx; i++)
        invfact[i] = modinv(fact[i]);
}

int main() {
    precompute();
    int n; cin >> n;
    ll ans = 0;
    ll K = 1;
    for (int nbDraw = 0; nbDraw < n; nbDraw++) {
        int rem = n-nbDraw;
        ll k = 1;
        if (rem%2 == 1) {
            k = (k * fast_pow(2, rem - 1)) % mod;
            k = (k * invfact[rem])%mod;
        }
        else {
            k = (k * fast_pow(2,rem))%mod;
            k = (k-C(rem, rem/2)+mod)%mod;
            k = (k*invfact[2])%mod;
            k = (k * invfact[rem])%mod;
        }
        k = (k*K)%mod;
        k = (k*fact[n])%mod;
        k = (k*invfact[nbDraw])%mod;
        ans = (ans + k)%mod;
        K = (K*2)%mod;
    }
    cout << ans;
}