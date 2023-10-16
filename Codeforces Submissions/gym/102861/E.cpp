#include <bits/stdc++.h>
#define ll unsigned long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

const int N = 1e5+7;
const int K = 20;
vector<vector<int>> tree(N);
int age[N];

vector<int> party[N]; /// Left part only

int up[N][K];
int mx[N][K];
int depth[N];

void dfs(int node, int par = -1) {
    for (int ch : tree[node]) {
        if (ch == par)
            continue;
        depth[ch] = depth[node] + 1;
        up[ch][0] = node;
        mx[ch][0] = max(age[ch], age[node]);
        for (int j = 1; j < K; j++) {
            up[ch][j] = up[up[ch][j-1]][j-1];
            mx[ch][j] = max(mx[ch][j-1], mx[up[ch][j-1]][j-1]);
        }
        dfs(ch,node);
    }
}

int binary_lifting(int R, int node) {
    for (int j = K-1; j >= 0; j--) {
        if (mx[node][j] <= R) {
            node = up[node][j];
        }
    }
    return node;
}

int fentree[N];

int get(int x) {
    int res = 0;
    for (; x; x-= x&(-x))
        res+= fentree[x];
    return res;
}

void upd(int x, int val) {
    for (; x < N; x+=x&(-x)) {
        fentree[x]+=val;
    }
}

int ans[N];

void dfs2(int node, int par = -1) {
    for (int i : party[node]) {
        upd(i, 1);
    }
    ans[node] = get(age[node]);
    for (int ch : tree[node]) {
        if (ch == par)
            continue;
        dfs2(ch, node);
    }
    for (int i : party[node]) {
        upd(i, -1);
    }
}


int main() {
    SaveTime
    int n,m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a,ch; cin >> a >> ch;
        if (i != 1) {
            tree[i].push_back(ch);
            tree[ch].push_back(i);
        }
        age[i] = a;
    }
    for (int i = 0; i < K; i++)
        up[1][i] = 1;
    dfs(1);
    for (int i = 0; i < m; i++) {
        int host,L,R; cin >> host >> L >> R;
        host = binary_lifting(R, host);
        party[host].push_back(L);
    }
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}