//64%
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const ll N = 4e5+7;
vector<vector<pair<ll,ll>>> MST(N);
ll par[N];

vector<vector<ll>> adj(N);

ll Find(ll node) {
    if (par[node] == node)
        return node;
    return par[node] = Find(par[node]);
}

bool Union(ll n1, ll n2) {
    ll a1 = Find(n1);
    ll a2 = Find(n2);
    if (a1 == a2)
        return true;
    par[a1] = a2;
    return false;
}

set<ll> vs;

void dfs(ll node) {
    if (vs.count(node)) {
        return;
    }
    vs.insert(node);
    for (ll i : adj[node])
        dfs(i);
}

int main() {
    SaveTime
    ll m; cin >> m;
    for (ll i = 1; i < N; i++)
        par[i] = i;
    vector<tuple<ll,ll,ll>> graph(m);
    map<ll,ll> nb;
    set<string> s;
    map<string,ll> mp;
    for (ll i = 0; i < m; i++) {
        string a1,b1; cin >> a1 >> b1;
        ll a,b;
        if (s.count(a1)) {
            a = mp[a1];
        }
        else {
            s.insert(a1);
            mp[a1] = (ll) s.size();
            a = mp[a1];
        }

        if (s.count(b1)) {
            b = mp[b1];
        }
        else {
            s.insert(b1);
            mp[b1] = (ll) s.size();
            b = mp[b1];
        }

        ll w; cin >> w;
        nb[w]++;
        graph[i] = {w,a,b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sort(graph.begin(), graph.end());
    long long ans = 0;
    bool ok = false;
    for (ll i = 0; i < m; i++) {
        ll a = get<1>(graph[i]), b = get<2>(graph[i]), w = get<0>(graph[i]);
        if (Union(a,b))
            continue;
        if (! ok)
           ans+= 1LL*w*nb[w];
        else 
           ans+= 1LL*w;
        MST[a].push_back({w,b});
        MST[b].push_back({w,a});
        bool ent = false;
        while (i != m-1 && ! ok) {
            ent = true;
            auto [w1,a1,b1] = graph[i+1];
            if (w1 != w)
                break;
            i++;
        }
        if (ent)
            ok = true;
    }
    dfs(1);
    if (vs.size() != s.size()) {
        cout << -1 << '\n';
    }
    else {
        cout << ans;
    }
}
