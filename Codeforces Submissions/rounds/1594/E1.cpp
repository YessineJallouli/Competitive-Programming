#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mod = 1e9 + 7;

int N;

ll solve(ll n) {
    if (n == 1)
        return 4;
    ll ans = solve(n-1);
    ans = (ans*ans)%mod;
    if (n != N)
        ans = (ans*4)%mod;
    else
        ans = (ans*6)%mod;
    return ans;
}

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << 6;
        return 0;
    }
    N = n;
    cout << solve(n);
}