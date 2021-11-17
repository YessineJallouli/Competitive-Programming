//https://codeforces.com/problemset/problem/348/C
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;
const int SQ = 316;
ll inter[SQ][N];
int vis[N];
ll sum[N];
ll added[N];
ll a[N];

int main() {
    SaveTime
    int n,m,q; cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> st(m);
    vector<pair<int,int>> big_set;
    int idBig[m];
    memset(idBig, -1, sizeof idBig);
    int nb1 = 0;
    for (int i = 0; i < m; i++) {
        int nb; cin >> nb;
        if (nb > sqrt(n)) {
            big_set.push_back({i, nb1});
            idBig[i] = nb1++;
        }
        for (int j = 0; j < nb; j++) {
            int id; cin >> id;
            id--;
            st[i].push_back(id);
        }
    }
    for (int i = 0; i < m; i++) {
        if (idBig[i] == -1)
            continue;
        int id = idBig[i];
        for (int j : st[i]) {
            sum[id]+= a[j];
        }
    }
    memset(vis, false,sizeof vis);
    for (int i = 0; i < big_set.size(); i++) {
        int id1 = big_set[i].first;
        for (int nb : st[id1]) {
            vis[nb] = true;
        }
        for (int j = 0; j < m; j++) {
            int res = 0;
            for (int nb : st[j]) {
                if (vis[nb])
                    res++;
            }
            int vr1 = big_set[i].second;
            inter[vr1][j] = res;
        }
        for (int nb : st[id1]) {
            vis[nb] = false;
        }
    }

    while (q--) {
        char c; cin >> c;
        if (c == '+') {
            int id, x; cin >> id >> x;
            id--;
            if (idBig[id] == -1) {
                for (int i = 0; i < SQ; i++) {
                    sum[i]+= x * inter[i][id];
                }
                for (int i : st[id]) {
                    a[i]+= x;
                }
            }
            else {
                added[idBig[id]]+= x;
                for (int i = 0; i < SQ; i++) {
                    sum[i]+= x * inter[i][id];
                }
            }
        }
        else {
            int id; cin >> id;
            id--;
            if (idBig[id] == -1) {
                ll res = 0;
                for (int i = 0; i < SQ; i++) {
                    res+= added[i] * inter[i][id];
                }
                for (int i : st[id])
                    res+= a[i];
                cout << res << '\n';
            }
            else {
                id = idBig[id];
                cout << sum[id] << '\n';
            }
        }
    }
}
