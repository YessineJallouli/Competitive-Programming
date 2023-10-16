#include <bits/stdc++.h>
#define ll long long
using namespace std;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ll n; cin >> n;
    ll N = n;
    ll p = 1;
    for (ll i = 2; i*i <= n; i++) {
        ll nb = 0;
        while (N%i == 0) {
            nb++;
            N/=i;
        }
        if (nb%2) {
            p*= i;
        }
    }
    if (N != 1) {
        p*= N;
    }
    ll k = n/p+1;
    ll h = sqrt(k)+1;
    k = h*h;
    p*= k;
    cout << p-n;
}