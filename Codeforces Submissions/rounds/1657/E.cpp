#include <bits/stdc++.h>
using namespace std;

const int mx = 10000;
int mod = 998244353;
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
    ios_base::sync_with_stdio(false), cin.tie(0);
    precompute();
    int n,k; cin >> n >> k;
    n--;
    long long ans = 0;
    long long dp[k+1][n+1];
    memset(dp , 0,sizeof dp);
    for (int i = 0; i <= k; i++) {
        dp[i][0] = 1;
    }
    for (int c = 1; c <= k; c++) {
        for (int nbChosen = 1; nbChosen <= n; nbChosen++) {
            for (int j = 0; j <= nbChosen; j++) {
                dp[c][nbChosen] = (dp[c][nbChosen] + dp[c-1][nbChosen-j]*C(nbChosen, j)%mod * fast_pow(k+1-c, j*(nbChosen-j) + j*(j-1)/2)%mod)%mod;
            }
        }
    }
    cout << dp[k][n];
}