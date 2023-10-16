#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5+7;
bool marked[N];
int sieve[N];
int subtree_size[N];
vector<pair<int,int>> tree[N];
int t[N];


int cnt[4];
map<long long,int> nb;

long long ans = 0;

int type(int n) {
    if (n == 1)
        return 1; // one
    if (sieve[n] == n)
        return 2; // prime
    if (n/sieve[n] == sieve[n/sieve[n]] && sieve[n] != n/sieve[n])
        return 3; // product of two distinct primes
    return 4;
}

int getSubtreeSize(int node, int par = -1) {
    subtree_size[node] = 1;
    for (auto [i,w] : tree[node]) {
        if (i != par && ! marked[i]) {
            subtree_size[node]+= getSubtreeSize(i, node);
        }
    }
    return subtree_size[node];
}

int get_centroid(int node, int sz, int par = -1) {
    for (auto [i,w] : tree[node]) {
        if (i != par && ! marked[i]) {
            if (subtree_size[i]*2 > sz) {
                return get_centroid(i, sz, node);
            }
        }
    }
    return node;
}

void get_cnt(long long product, int typeProduct, int node, bool filling, int par) {
    if (typeProduct == 4)
        return;
    if (filling) {
        nb[product]++;
        cnt[typeProduct]++;
    }
    else {
        if (typeProduct == 1)
            ans+= cnt[3];
        else if (typeProduct == 3)
            ans+= cnt[1];
        else if (typeProduct == 2) {
            ans += cnt[2] - nb[product];
        }
    }
    for (auto [i,w] : tree[node]) {
        if (i != par && ! marked[i]) {
            if (t[w] == 4)
                continue;
            if (typeProduct == 3 && w == 1)
                get_cnt(product, typeProduct, i, filling, node);
            else if (typeProduct == 2) {
                if (t[w] == 2 && w != product)
                    get_cnt(1LL*product*w,3,i,filling,node);
                else if (t[w] == 1)
                    get_cnt(product*w,typeProduct,i,filling,node);
            }
            else if (typeProduct == 1)
                get_cnt(product*w,t[w],i,filling,node);
        }
    }
}

void centroid(int node = 1) {
    cnt[1] = 1;
    int c = get_centroid(node, getSubtreeSize(node));
    for (auto [i,w] : tree[c]) {
        if (! marked[i]) {
            get_cnt(w, t[w],i, false, c);
            get_cnt(w, t[w],i, true, c);
        }
    }
    marked[c] = true;
    cnt[2] = cnt[3] = 0;
    nb.clear();
    for (auto [i,w] : tree[c]) {
        if (! marked[i]) {
            centroid(i);
        }
    }
}


int main() {
    freopen("evaluations.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    memset(sieve, -1, sizeof sieve);
    for (int i = 2; i < N; i++) {
        if (sieve[i] == -1) {
            for (int j = i; j < N; j+= i)
                if (sieve[j] == -1)
                    sieve[j] = i;
        }
    }
    for (int i = 1; i < N; i++)
        t[i] = type(i);

    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        ans = 0;
        nb.clear();
        int n; cin >> n;
        for (int i = 0; i <= n; i++) {
            tree[i].clear();
            marked[i] = false;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            tree[a].emplace_back(b,w);
            tree[b].emplace_back(a,w);
        }
        centroid();
        cout << "Case " << ii << ": " << ans << '\n';
    }
}