//
// Created by Yessine on 23/11/2021.
//

#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const ll N = 2e5+7;
ll mod = 1e9+7;

ll pow2[N];

bool cmp(int a,int b) {
    if (a%2 < b%2)
        return true;
    return false;
}

ll pr(vector<ll> b) {
    ll n = b.size();
    map<ll,ll> nb;
    set<ll> s;
    for (ll i = 0; i < n; i++) {
        ll p = 1;
        while (b[i]%2 == 0) {
            p*= 2;
            b[i]/= 2;
        }
        b[i] = p;
        s.insert(b[i]);
        nb[b[i]]++;
    }
    sort(b.begin(), b.end());
    ll res = 0;
    ll cum = 0;
    for (ll i : s) {
        cum+= nb[i];
        if (nb[i] == 1)
            continue;
        res= ((res + (pow2[nb[i]-1]-1) * pow2[n-cum])%mod)%mod;
        //cout << i << ' ' << nb[i] << ' ' << res << '\n';
    }
    return res;
}


int main() {
    ll n; cin >> n;
    pow2[0] = 1;
    for (ll i = 1; i <= n; i++) {
        pow2[i] = (pow2[i-1]*2)%mod;
    }
    ll a[n];
    vector<ll> v;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if ((a[i]%2) ==0)
            v.push_back(a[i]);
    }
    sort(a,a+n, cmp);
    ll ans = 0;
    ll lastImp = -1;
    ll cumImp = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i]%2 == 1) {
            lastImp = i;
            cumImp = (cumImp+pow2[i])%mod;
        }
        if (a[i]%2 == 1) {
            ans = (ans + pow2[i])%mod;
        }
        else {
            if (lastImp != -1) {
                ans = (ans+cumImp)%mod;
            }
        }
    }
    ans = (ans+pr(v))%mod;
    cout << ans;
}