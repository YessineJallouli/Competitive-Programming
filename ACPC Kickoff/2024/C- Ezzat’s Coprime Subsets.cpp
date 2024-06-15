#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6+7;

long long fact[N];
long long invfact[N];
long long mob[N];
bool P[N];

int cnt[N];

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
    for (int i = 1; i < N; i++)
        fact[i] = fact[i-1] * i % mod;
    for (int i = 0; i < N; i++)
        invfact[i] = modinv(fact[i]);
}

long long C(int n, int k) {
    if (k > n)
        return 0;
    return fact[n] * invfact[n-k] % mod * invfact[k] % mod;
}

int main() {
    precompute();

    int n,k; cin >> n >> k;
    ll c = C(n-1, k-1);
    ll ans = 0;
    ll a[n];

    for (int i = 2; i < N; i++) {
        mob[i] = -1; P[i] = true;
    }

    for (int i = 2; i < N; i++) {
        if (P[i]) {
            mob[i] = 1;
            for (int j = i+i; j < N; j+= i) {
                P[j] = false;
                mob[j] = j%(i*i) == 0 ? 0 : -mob[j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        ans = (ans + (a[i]*c)%mod)%mod;
    }

    for (int i = 2; i < N; i++) {
        int nb = 0;
        for (int j = i; j < N; j+= i) {
            nb+= cnt[j];
        }
        if (nb < k)
            continue;
        ll contribution = 0;
        c = C(nb-1, k-1);
        for (int j = i; j < N; j+= i) {
            contribution = (contribution + ((cnt[j]*j)%mod*c)%mod)%mod;
        }
        contribution = contribution*mob[i];
        ans = (ans - contribution+mod)%mod;
    }
    cout << ans;
}
