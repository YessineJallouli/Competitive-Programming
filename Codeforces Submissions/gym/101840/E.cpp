//
// Created by yessine on 11/12/22.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<pair<int,int>> tree[N];
int sieve[N];

int ans = 0;


int type(int n) {
    if (n == 1)
        return 1; // one
    if (sieve[n] == n)
        return 2; // prime
    if (n/sieve[n] == sieve[n/sieve[n]] && sieve[n] != n/sieve[n])
        return 3; // product of two distinct primes
    return 4;
}

void dfs(int node, int p = 1, int par = -1) {
    if (type(p) == 3)
        ans++;
    if (type(p) == 4)
        return;
    for (auto [i,w] : tree[node]) {
        if (i != par) {
            dfs(i, p*w, node);
        }
    }
}

int main() {
    freopen("evaluations.in", "r", stdin);
    memset(sieve, -1, sizeof sieve);
    for (int i = 2; i < N; i++) {
        if (sieve[i] == -1) {
            for (int j = i; j < N; j+= i)
                if (sieve[j] == -1)
                    sieve[j] = i;
        }
    }

    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        int n; cin >> n;
        for (int i = 0; i <= n; i++)
            tree[i].clear();

        for (int i = 0; i < n - 1; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            tree[a].emplace_back(b,w);
            tree[b].emplace_back(a,w);
        }
        for (int i = 1; i <= n; i++) {
            dfs(i);
        }
        cout << "Case " << ii << ": " << ans/2 << '\n';
    }
}