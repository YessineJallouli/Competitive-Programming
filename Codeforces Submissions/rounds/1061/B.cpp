#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
    SaveTime;
    ll n,m; cin >> n >> m;
    ll a[n];
    set<ll> s;
    map<ll,ll> nb;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        nb[a[i]]++;
        s.insert(a[i]);
    }
    sort(a, a+n);
    nb[a[n-1]]--;
    ll cum = 0;
    for (ll i : s) {
        cum = min(i, cum + nb[i]);
    }
    map<ll,ll> vs;
    ll nbVar = 0;
    for (ll i = 0; i < n-1; i++) {

    }
    if (a[0] == a[n-1]) {
        ll ans = 0;
        if (a[0] <= n) {
            ans = (a[0]-1)*n;
        }
        else {
            ans = (a[0]-1)*(n-1);
            ans+= n-1;
        }
        cout << ans;
        return 0;
    }
    ll ans = 0;
    for (ll i = 0; i < n-1; i++) {
        ans+= a[i]-1;
    }
    cout << ans+min(cum, a[n-1]-1);
}