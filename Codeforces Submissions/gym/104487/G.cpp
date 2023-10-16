#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3007;
int a[N];
vector<vector<int>> adj(N);

int n,m,k;

ll ans = 0;
ll s = 0;

multiset<ll> bestK;
multiset<ll> rem;

void dfs(int node, int depth = 1, int par = -1) {
    if (a[node] > 0) {
        if (bestK.size() < k) {
            s+= a[node];
            bestK.insert(a[node]);
        }
        else {
            if (*bestK.begin() < a[node]) {
                int b = *bestK.begin();
                bestK.erase(bestK.find(*bestK.begin()));
                bestK.insert(a[node]);
                s-= b;
                s+= a[node];
                rem.insert(b);
            }
            else {
                rem.insert(a[node]);
            }
        }
        ans = max(ans, s);
    }

    if (!((depth >= m) || (adj[node].size() == 1 && par != -1))) {
        for (int ch: adj[node]) {
            if (ch == par)
                continue;
            dfs(ch, depth + 1, node);
        }
    }
    if (a[node] > 0) {
        if (bestK.count(a[node])) {
            bestK.erase(bestK.find(a[node]));
            s-= a[node];
            if (! rem.empty()) {
                int b = *rem.rbegin();
                s+= b;
                rem.erase(rem.find(b));
                bestK.insert(b);
            }
        }
        else {
            rem.erase(rem.find(a[node]));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            cin >> a[i];
        }
        for (int i = 0; i < n-1; i++) {
            int x,y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            bestK.clear();
            rem.clear();
            s = 0;
            dfs(i);
        }
        cout << ans << '\n';
    }
}