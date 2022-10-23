//100%
#include<bits/stdc++.h>
#define ll long long
using namespace std;


const int N = 1000;
int par[N];

int Find(int node) {
    if (par[node] == node)
        return node;
    return par[node] = Find(par[node]);
}

bool Union(int n1, int n2) {
    int a1 = Find(n1);
    int a2 = Find(n2);
    if (a1 == a2)
        return true;
    par[a1] = a2;
    return false;
}

int n;

int mst(vector<tuple<int,int,int>> &edge) {
    for (int i = 1; i <= n; i++)
        par[i] = i;
    sort(edge.begin(), edge.end());
    int ans = 0;
    int nb = 0;
    for (int i = 0; i < edge.size(); i++) {
        int a = get<1>(edge[i]), b = get<2>(edge[i]), w = get<0>(edge[i]);
        if (Union(a,b))
            continue;
        ans+= w;
        nb++;
    }
    if (nb == n-1)
        return ans;
    return 1e8;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int m; cin >> m;
    vector<tuple<string, string,int,int>> sedges;
    set<string> s;
    for (int i = 0; i < m; i++) {
        string a,b; cin >> a >> b;
        int c,h; cin >> c >> h;
        s.insert(a);
        s.insert(b);
        sedges.emplace_back(a,b,c,h);
    }
    n = (int) s.size();
    map<string, int> mp;
    int nb = 0;
    for (string ch : s) {
        mp[ch] = ++nb;
    }

    vector<tuple<int,int,int,int>> edges;
    set<int> nonUpgraded;
    for (int i = 0; i < m; i++) {
        auto [a,b,c,h] = sedges[i];
        edges.emplace_back(mp[a], mp[b], c, h);
        if (h == 1) {
            nonUpgraded.insert(mp[a]);
            nonUpgraded.insert(mp[b]);
        }
    }
    vector<int> nUpg;
    for (int i : nonUpgraded)
        nUpg.push_back(i);

    int ans = INT_MAX;
    int cnt = (int) nUpg.size();
    for (int i = 0; i < (1 << cnt); i++) {
        bool canBeUsed[m];
        for (int j = 0; j < m; j++)
            canBeUsed[j] = false;
        int construction = 0;
        for (int j = 0; j < cnt; j++) {
            if (i & (1 << j)) {
                construction+= 10000;
                for (int k = 0; k < m; k++) {
                    auto [a,b,c,h] = edges[k];
                    if (h == 0)
                        canBeUsed[k] = true;
                    else if (h == 1) {
                        if (a == nUpg[j] || b == nUpg[j])
                            canBeUsed[k] = true;
                    }
                }
            }
        }
        vector<tuple<int,int,int>> newEdges;
        for (int j = 0; j < m; j++) {
            if (canBeUsed[j]) {
                auto [a,b,c,h] = edges[j];
                newEdges.emplace_back(c,a,b);
            }
        }
        sort(newEdges.begin(), newEdges.end());
        ans = min(ans, construction + mst(newEdges));
    }
    cout << ans << '\n';

}
