#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isSqrt(ll n) {
    ll k = sqrt(n);
    return (k*k == n);
}

void solve(ll n) {
    set<ll> s;
    for (ll i = 1; i*i < n; i++) {
        if (n%i == 0) {
            s.insert(i);
        }
    }
    if (isSqrt(n)) {
        cout << (int) sqrt(n) << ' ' << s.size()*2+1;
    }
    else {
        cout << n << ' ' << s.size();
    }
}

int main() {
    ll n; cin >> n;
    solve(n);
}