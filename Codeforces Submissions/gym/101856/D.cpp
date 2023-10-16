#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+7;
int nb[N];
bool vis[N];

int par[N];

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


int main()
{
    freopen("dream.in", "r", stdin);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(nb, 0, sizeof nb);
        memset(vis, false, sizeof vis);

        for (int i = 0; i < N; i++)
            par[i] = i;

        vector<int> pos[N];

        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            nb[x]++;
            pos[x].push_back(i);
        }
        ll ans = 0;
        for (int i = N; i >= 1; i--) {
            int cnt = 0;
            vector<int> v;
            for (int j = i; j < N; j+= i) {
                for (int node : pos[j])
                    v.push_back(node);
            }
            for (int node : v) {
                if (Find(node) == Find(v.back())) {
                    continue;
                }
                Union(node, v.back());
                cnt++;
            }
            if (cnt > 0)
                ans+= 1LL*cnt*i;
        }
        cout << "Case " << t << ": " << ans << '\n';
    }
}