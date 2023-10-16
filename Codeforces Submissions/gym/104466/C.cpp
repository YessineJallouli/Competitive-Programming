#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll n,m,k; cin >> n >> m >> k;
    ll wormhole[k];
    for (ll i = 0; i < k; i++) {
        cin >> wormhole[i];
    }
    vector<vector<ll>> adj(n+1);
    vector<vector<ll>> adj1(n+1);

    for (ll i = 0; i < m; i++) {
        ll a,b; cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
        adj1[a].push_back(b);
        adj1[b].push_back(a);
    }

    bool visited[n+1];
    ll d[n+1];
    memset(d, 0, sizeof d);
    memset(visited, false, sizeof visited);
    vector<ll> v = {n};
    ll dist = 0;
    while (! v.empty()) {
        vector<ll> aux;
        for (ll i: v) {
            visited[i] = true;
            if (d[i] == 0) {
                d[i] = dist;
            }
        }
        for (ll i : v) {
            for (ll ch : adj[i]) {
                if (visited[ch])
                    continue;
                visited[ch] = true;
                aux.push_back(ch);
            }
        }
        dist++;
        aux.swap(v);
    }

    memset(visited, false, sizeof visited);

    ll d1[n+1];
    memset(d1, 0, sizeof d1);
    v = {1};
    dist = 0;
    while (! v.empty()) {
        vector<ll> aux;
        for (ll i: v) {
            visited[i] = true;
            if (d1[i] == 0) {
                d1[i] = dist;
            }
        }
        for (ll i : v) {
            for (ll ch : adj1[i]) {
                if (visited[ch])
                    continue;
                visited[ch] = true;
                aux.push_back(ch);
            }
        }
        dist++;
        aux.swap(v);
    }

    vector<ll> res;
    res.push_back(d[1]*(k-1));
    ll sum = 0;
    for (ll i = 0; i < k; i++) {
        sum+= d[wormhole[i]];
    }
    for (ll i = 0; i < k; i++) {
        ll s = sum-d[wormhole[i]];
        ll h = (k-1)*(d1[wormhole[i]]);
        ll all = h+s;
        res.push_back(all);
    }

    sort(res.begin(), res.end());
    ll g = gcd(k-1, res[0]);
    cout << res[0]/g << '/' << (k-1)/g;
}