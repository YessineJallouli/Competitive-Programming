#include <bits/stdc++.h>
using namespace std;

const int mx = 1001;
int mod = 998244353;
long long fact[mx];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < mx; i++)
        fact[i] = fact[i-1] * i % mod;
}

int main() {
    precompute();
    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n%2) {
            cout << 0 << '\n';
        }
        else
            cout << 1LL*fact[n/2]*fact[n/2]%mod << '\n';
    }
}