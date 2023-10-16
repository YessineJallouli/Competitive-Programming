#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int mx[N];
int dp[N];

void dfs(int u, const vector<vector<int>> &tree, int p = -1) {
    mx[u] = 0;
    for (auto v : tree[u]) {
        if (v == p)
            continue;
        dfs(v,tree, u);
        mx[u] = max(1+mx[v], mx[u]);
    }
}

void reroot(int u, const vector<vector<int>> &tree, int p = -1, int m = 0) {
    dp[u] = max(m, mx[u]);
    multiset<int> st;
    st.insert(-(m));
    for (auto v : tree[u]) {
        if (v == p)
            continue;
        st.insert(-(mx[v]+1));
    }
    for (auto v : tree[u]) {
        if (v == p)
            continue;
        st.erase(st.find(-(mx[v]+1)));
        reroot(v,tree,u, -*st.begin()+1);
        st.insert(-(mx[v]+1));
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> tree(n+1);
    for (int i = 0; i < n-1; i++) {
        int x,y; cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, tree);
    reroot(1, tree);
    vector<int> v;
    int nb[n+1];
    memset(nb, 0, sizeof nb);
    for (int i = 1; i <= n; i++) {
        nb[dp[i]]++;
    }
    int k = n;
    int pr = 0;
    vector<int> h;
    bool fst = true;
    for (int i = n; i >= 1; i--) {
        k-= nb[i];
        if (nb[i] != 0 && fst) {
            k++;
            fst = false;
        }
        h.push_back(k);
    }
    reverse(h.begin(), h.end());
    for (int i : h)
        cout << i << ' ';
}