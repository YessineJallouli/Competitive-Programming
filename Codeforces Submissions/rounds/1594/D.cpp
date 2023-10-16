#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 8e5+7;
int color[mx];

int ans = 0;

int n;

bool isBipartite(vector<vector<int>> &graph) {
    int NB = graph.size();
    for (int i = 0; i < NB; i++) {
        if (color[i] != -1)
            continue;
        int cl = 0;
        int NB1 = 0, NB2 = 0;
        vector<int> b = {i};
        while (!b.empty()) {
            for (int v : b) {
                if (cl) {
                    if (v > 0 && v <= n)
                        NB1++;
                }
                else {
                    if (v > 0 && v <= n)
                        NB2++;
                }
                color[v] = cl;
            }
            vector<int> aux;
            for (int v : b) {
                for (int ch : graph[v]) {
                    if (color[ch] == -1) {
                        aux.push_back(ch);
                        color[ch] = cl^1;
                    }
                    else if (color[ch] == color[v])
                        return false;
                }
            }
            cl^= 1;
            b.swap(aux);
        }
        ans+= max(NB1, NB2);
    }
    return true;
}

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        int m; cin >> n >> m;
        for (int i = 0; i <= n+m+10; i++)
            color[i] = -1;
        vector<vector<int>> graph(n+m+1);
        int buffer = n+1;
        for (int i = 0; i < m; i++) {
            int a,b; cin >> a >> b;
            string s; cin >> s;
            if (s[0] == 'i') {
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
            else {
                graph[a].push_back(buffer);
                graph[buffer].push_back(b);
                graph[b].push_back(buffer);
                graph[buffer].push_back(a);
                buffer++;

            }
        }
        ans = 0;
        if (! isBipartite(graph)) {
            cout << -1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }
}