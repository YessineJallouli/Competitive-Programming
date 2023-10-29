//100%
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int delta[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

int main() {
    SaveTime
    int n,m; cin >> n >> m;
    int g[n][m];
    double ans[n][m];
    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            ans[i][j] = 1.0;
            pq.emplace(g[i][j], i, j);
        }
    }
    while (! pq.empty()) {
        auto [a,b,c] = pq.top();
        pq.pop();
        int mn = a;
        vector<tuple<int,int,int>> v;
        for (int t = 0; t < 4; t++) {
            int newB = b+delta[t][0];
            int newC = c+delta[t][1];
            if (newB >= 0 && newB < n && newC >= 0 && newC < m) {
                if (g[newB][newC] < a)
                    v.emplace_back(g[newB][newC], newB, newC);
            }
        }
        int nb = (int) v.size();
        for (auto [x, y, z]: v) {
            ans[y][z] += ans[b][c] / nb;
            //ans[b][c]-= ans[b][c] / nb;
        }
        if (nb != 0)
            ans[b][c] = 0;
    }
    double res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res = max(res, ans[i][j]);
        }
    }
    cout.precision(15);
    cout << fixed << res;
}
