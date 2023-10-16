#include <bits/stdc++.h>
#define ll long long
using namespace std;
int const N=1e6;

int main() {

    ios_base::sync_with_stdio(false);
    vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;
    vector<ll> primes;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (long long)i * i <= N) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    ll n,r,p;
    cin >> n >> r >> p;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<ll> dp(n+1,LLONG_MAX);
    dp[n]=0;
    for(ll i=n;i;i--){
        if(dp[i]==LLONG_MAX) continue;
        dp[1]=min(dp[1],dp[i]+p*(i-1)+r);
        for(ll prime:primes){
            ll k=i/prime;
            if(prime>=i) break;
            if(i%prime) k++;
            dp[k] = min(dp[k], dp[i] + (prime - 1) * p + r);
            for (int dec = 1; dec < 100; dec++) {
                if (prime-dec < 3)
                    continue;
                if (prime+dec > N)
                    continue;
                if (prime+dec >= i)
                    continue;
                int k1=i/(prime+dec),k2=i/(prime-dec);
                if (i % (prime + dec)) k1++;
                if (i % (prime - dec)) k2++;
                dp[k1] = min(dp[k1], dp[i] + (prime+dec-1) * p + r);
                if (prime > 3) dp[k2] = min(dp[k2], dp[i] + (prime - dec-1) * p + r);
            }
        }
    }
    cout << dp[1];

}