#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+7;
ll memo[N];

const int mod = 998244353;

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

// k is the number of mismatch

ll solve(int k, int n, ll a = 0, ll b = 0) {
    if (k == 0)
        return memo[k] = 0;
    if (memo[k] != -1)
        return memo[k];
    if (k == n) {
        return memo[k] = 1 + solve(k-1, n, 1,1);
    }

    ll H = (n-(n*a)%mod + (k*a)%mod + mod)%mod;
    ll A = (H*modinv(H))%mod;
    ll B = ((n*b)%mod - (k*b)%mod + n + mod)%mod;
    B = (B* modinv(H))%mod;
    ll ans = (((k*solve(k-1,n,A,B))%mod + ((n*b)%mod-(k*b)%mod+n+mod)%mod) * modinv(H))%mod;
    return memo[k] = ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; string a,b; cin >> n >> a >> b;
        int k = 0;
        for (int i = 0; i <= n; i++)
            memo[i] = -1;
        for (int i = 0; i < n; i++) {
            k+= (a[i] != b[i]);
        }
        solve(n,n);
        cout << memo[k] << '\n';
    }
}