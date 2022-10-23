//100%
#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,string>
using namespace std;

const int N = 1e4+7;
int distFive[N];
map<pair<int,int>, bool> vis;
vector<vector<pair<int,int>>> graph(N);

set<int> fiveNode;

void dfs(int node, int par, int sum, int depth) {

    if (vis[{node, par}] || vis[{par, node}])
        return;
    if (depth == 5) {
        fiveNode.insert(node);
        distFive[node] = min(distFive[node], sum);
        return;
    }
    vis[{node, par}] = vis[{par, node}] = true;
    for (auto [ch, w] : graph[node]) {
        dfs(ch, node, sum+w, depth+1);
    }
    vis[{node, par}] = vis[{par, node}] = false;
}

int inf = INT_MAX;

void djiksra(int root) {
    vector<int> d(N);
    vector<int> p(N);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    d.assign(N, inf);
    p.assign(N, -1);
    d[root] = 0;
    q.push({0, root});

    while (!q.empty()) {
        int v = q.top().second;
        q.pop();
        for (auto edge : graph[v]) {
            int node = edge.first;
            int w = edge.second;
            if (w + d[v] < d[node]) {
                d[node] = w + d[v];
                p[node] = v;
                q.push({d[node], node});
            }
        }
    }

    for (int i = 1; i < N; i++) {
        distFive[i] = min(distFive[i], distFive[root] + d[i]);
    }


}

int main() {
    int n,m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a,b,w; cin >> a >> b >> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    for (int i = 0; i < N; i++) {
        distFive[i] = INT_MAX;
    }

    dfs(1,1, 0,0);
    for (int root : fiveNode) {
        djiksra(root);
    }
    for (int i = 1; i <= n; i++) {
        cout << distFive[i] << '\n';
    }
}
