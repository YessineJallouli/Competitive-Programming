#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 1e6+7;

int par[mx];

int Find(int node) {
    if (par[node] == node)
        return node;
    return par[node] = Find(par[node]);
}

void Union(int n1, int n2) {
    int a1 = Find(n1);
    int a2 = Find(n2);
    if (a1 == a2)
        return;
    par[a1] = a2;
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,m; cin >> n >> m;
        int cnt[m+1];
        for (int i = 0; i <= m; i++) {
            par[i] = i;
            cnt[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        ll s = 0;
        for (int g = m; g >= 1; g--) {
            vector<int> v;
            for (int i = g; i <= m; i+= g) {
                if (cnt[i] != 0) {
                    v.push_back(i);
                }
            }
            int sz = (int) v.size();
            if (! v.empty()) {
                int rt = v[0];
                s+= 1LL*g*(cnt[rt]-1);
                cnt[rt] = 1;
                for (int j = 1; j < sz; j++) {
                    if (Find(v[j]) != Find(v[0])) {
                        s+= 1L*g*cnt[v[j]];
                        Union(v[0], v[j]);
                    }
                }
            }
        }
        cout << s << '\n';
    }
}