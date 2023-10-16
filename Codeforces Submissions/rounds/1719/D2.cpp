#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int inf = 1e9;

const int N = 2e5+7;

vector<int> d(N);
vector<int> p(N);
vector<vector<pair<int,int>>> graph(N);
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {

        int n;
        cin >> n;

        for (int i = 0; i <= n; i++) {
            d[i] = inf;
            p[i] = -1;
            graph[i].clear();
        }


        int v[n];
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        set<int> ss;

        int xr = 0;

        map<int,int> idxr;

        for (int i = 0; i < n; i++) {
            xr = xr^v[i];
            if (xr == 0 && graph[0].empty()) {
                graph[0].push_back({i+1, i});
            }
            else if (idxr[xr] != 0) {
                int id = idxr[xr]-1;
                graph[id+1].push_back({i+1, i-id-1});
            }
            idxr[xr] = i+1;
        }

        for (int i = 0; i < n; i++) {
            int w = 1;
            if (v[i] == 0)
                w = 0;
            graph[i].push_back({i + 1, w});
        }
        for (int i = 0; i < n - 1; i++) {
            int nbZ = 0;
            int w = 0;
            if (v[i] == 0)
                nbZ++;
            if (v[i + 1] == 0)
                nbZ++;
            if (nbZ == 1 || v[i] == v[i + 1])
                w = 1;
            else
                w = 2;
            graph[i].push_back({i + 2, w});
        }

        for (int i = 0; i < n - 2; i++) {
            int x = v[i] ^ v[i + 1] ^ v[i + 2];
            int w = 0;
            if (x == 0) {
                w = 2;
            } else {
                w = 3;
            }
            graph[i].push_back({i + 3, w});
        }

        //Shortest path from 1 to n
        d[0] = 0;
        q.push({0, 0});
        while (!q.empty()) {
            int v = q.top().second;
            q.pop();
            for (auto edge: graph[v]) {
                int node = edge.first;
                int w = edge.second;
                if (w + d[v] < d[node]) {
                    d[node] = w + d[v];
                    p[node] = v;
                    q.push({d[node], node});
                }
            }
        }
        if (d[n] == inf) {
            cout << -1;
            return 0;
        }
        cout << d[n] << '\n';
    }
}


//0 1 4 5 6 7 11 14 15 16 18 19 20 22 24 27 30 31 32 34 36 39 41 42 43 46 47 48 50 51 52 53 54 55 56 58 59 63 64 66