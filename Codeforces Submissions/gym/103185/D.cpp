//
// Created by Yessine on 24/11/2021.
//

#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

ll N = 1e5+7;


int main() {
    SaveTime
    ll n; cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n < 2) {
        cout << "N";
        return 0;
    }
    sort(a, a+n);
    set<ll> s;
    map<ll,ll> nb;
    for (ll i = 0; i < n; i++) {
        nb[a[i]]++;
        s.insert(a[i]);
    }
    set<ll> s1;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; (1<<j) < N; j++) {
            if (nb[i] & (1 << j)) {
                nb[i+j]++;
                nb[i]-= (1<<j);
            }
        }
    }
    ll cnt = 0;
    for (ll i = 0; i < 2*N; i++) {
        if (nb[i] != 0) {
            //cout << i << ' ' << nb[i] << '\n';
            cnt++;
        }
    }
    if (cnt <= 2) {
        cout << "Y";
    }
    else {
        cout << "N";
    }
}