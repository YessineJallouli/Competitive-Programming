#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e6+7;
int sieve[N];
ll dp[N];
ll nb[N];
int mod = 1e9+7;

void divisors(int n, vector<int> &P, vector<int> &D, int o = 0) {
    D.push_back(n);
    for (int i = o; i < P.size(); i++) {
        if (n%P[i]==0)
            divisors(n/P[i], P, D, i);
    }
}

int main() {
    SaveTime
    memset(sieve, -1, sizeof sieve);
    for (ll i = 2; i < N; i++) {
        if (sieve[i] == -1) {
            for (ll j = i; j < N; j+= i)
                if (sieve[j] == -1)
                    sieve[j] = i;
        }
    }
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> prime;
        int x = a[i];
        while (x != 1) {
            if (prime.empty() || prime.back() != sieve[x]) {
                prime.push_back(sieve[x]);
            }
            x/= sieve[x];
        }
        vector<int> div;
        divisors(a[i], prime, div);
        sort(div.rbegin(), div.rend());
        for (int d : div) {
            dp[d] = (dp[d] + dp[d-1])%mod;
        }
    }
    for (int i = 1; i < N; i++) {
        ans = (ans+dp[i])%mod;
    }
    cout << ans;
}