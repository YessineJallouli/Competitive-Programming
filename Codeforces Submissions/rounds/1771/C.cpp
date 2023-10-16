#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

const int N = 1e7;
int sieve[N];

map<int, bool> usd;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=10) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

long long mult(long long a, long long b, long long mod) {
    return (__int128)a * b % mod;
}

long long f(long long x, long long c, long long mod) {
    return (mult(x, x, mod) + c) % mod;
}

long long rho(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long y = x0;
    long long g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(abs(x - y), n);
    }
    return g;
}

int main() {
    SaveTime
    memset(sieve, -1, sizeof sieve);
    for (int i = 2; i < N; i++) {
        if (sieve[i] == -1) {
            for (int j = i; j < N; j+= i)
                if (sieve[j] == -1)
                    sieve[j] = i;
        }
    }
    int T; cin >> T;
    while (T--) {
        usd.clear();
        int n; cin >> n;
        int a[n];
        bool ans = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 1)
                continue;
            for (int j = 2; j <= 201; j++) {
                if (a[i] == 1)
                    break;
                bool ok = false;
                while (a[i]%j == 0) {
                    a[i]/= j;
                    ok = true;
                }
                if (usd[j] && ok) {
                    ans = true;
                }
                if (ok)
                    usd[j] = true;
            }
            if (MillerRabin(a[i])) {
                if (usd[a[i]])
                    ans = true;
                usd[a[i]] = true;
                a[i] = 1;
            }
            else if (a[i] > N) {
                int k = (int) rho(a[i]);
                if (usd[k])
                    ans = true;
                while (a[i]%k == 0) {
                    a[i]/= k;
                }
                usd[k] = true;
            }
            if (a[i] < N){
                while (a[i] != 1) {
                    int p = sieve[a[i]];
                    while (sieve[a[i]] == p) {
                        a[i]/= p;
                    }
                    if (usd[p])
                        ans = true;
                    usd[p] = true;
                }
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }

}