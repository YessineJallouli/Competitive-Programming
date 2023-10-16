#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;
vector<vector<int>> graph(N);
vector<vector<int>> inv(N);

vector<vector<int>> adj(N);

bool visite[N];
vector<int> comp;


void dfs(int node) {
    if (visite[node])
        return;
    visite[node] = true;
    comp.push_back(node);
    for (int i : adj[node])
        dfs(i);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int freq[2*n+1];
        map<pair<int,int>, int> m;
        for (int i = 0; i <= 2*n; i++) {
            freq[i] = 0;
            visite[i] = false;
            inv[i].clear();
            graph[i].clear();
            adj[i].clear();
        }
        bool ans = true;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            m[{a[i], b[i]}]++;
            freq[a[i]]++;
            freq[b[i]]++;
            if (freq[a[i]] > 2)
                ans = false;
            if (freq[b[i]] > 2)
                ans = false;
        }
        if (! ans) {
            cout << -1 << '\n';
            continue;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (m[{a[i], b[i]}] == 2) {
                res++;
                continue;
            }
            graph[a[i]].push_back(b[i]);
            inv[b[i]].push_back(a[i]);
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }
        res/= 2;
        for (int i = 0; i <= 2 * n; i++) {
            comp.clear();
            dfs(i);
            int sz = (int) comp.size();
            if (sz <= 1)
                continue;
            int nbEdge = 0;
            for (int node : comp)
                nbEdge+= (int) graph[node].size();

            for (int node : comp) {
                if (adj[node].size() == 1 || nbEdge == (int) comp.size()) {
                    // node is the root
                    int nb = 0;
                    int nd = node;
                    set<int> s;
                    s.insert(nd);
                    for (int j = 0; j < nbEdge; j++) {
                        bool ok = false;
                        for (int ch : graph[nd]) {
                            if (j == nbEdge-1 && nbEdge == (int) comp.size()) {
                                if (ch == node) {
                                    nb++;
                                    break;
                                }
                            }
                            if (s.count(ch))
                                continue;
                            ok = true;
                            s.insert(ch);
                            nd = ch;
                            nb++;
                            break;
                        }
                        if (! ok) {
                            for (int ch : inv[nd]) {
                                if (s.count(ch))
                                    continue;
                                s.insert(ch);
                                nd = ch;
                                break;
                            }
                        }
                    }
                    res+= min(nb, nbEdge-nb);
                    break;
                }
            }
        }
        cout << res << '\n';
    }
}