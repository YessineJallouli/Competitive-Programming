#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n], g[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        map<int,int> m;
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> g[i];
            s.insert(g[i]);
        }
        int nb = 0;
        for (int i : s) {
            m[i] = nb++;
        }
        vector<pair<int,int>> pos[n];
        for (int i = 0; i < n; i++) {
            g[i] = m[g[i]];
            pos[g[i]].emplace_back(a[i], i);
        }
        int lastRank[n];
        int rank[n];
        memset(lastRank, 0, sizeof lastRank);
        int no = false;
        for (int i = 0; i < n; i++) {
            sort(pos[i].begin(), pos[i].end());
            for (int j = 0; j < pos[i].size(); j++) {
                rank[pos[i][j].second] = j;
                if (j != (int) pos[i].size()-1 && pos[i][j].first == pos[i][j+1].first)
                    no = true;
            }
        }
        int p[n];
        int k = 1;
        for (int i = 0; i < n; i++) {
            if (lastRank[g[i]] == -1) {
                for (int j = 0; j <= rank[i]; j++) {
                    p[pos[g[i]][j].second] = k++;
                }
                lastRank[g[i]] = rank[i]+1;
            }
            else {
                for (int j = lastRank[g[i]]; j <= rank[i]; j++) {
                    p[pos[g[i]][j].second] = k++;
                }
                lastRank[g[i]] = max(lastRank[g[i]], rank[i]+1);
            }
        }
        if (no) {
            cout << -1 << '\n';
        }
        else {
            for (int i = 0; i < n; i++)
                cout << p[i] << ' ';
            cout << '\n';
        }
    }
}