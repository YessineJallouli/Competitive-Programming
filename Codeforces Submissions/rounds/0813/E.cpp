#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

vector<int> mrg(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    vector<int> res;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res.push_back(a[i++]);
        }
        else
            res.push_back(b[j++]);
    }
    while (i < a.size())
        res.push_back(a[i++]);
    while (j < b.size())
        res.push_back(b[j++]);
    return res;
}

const int N = 1e5+7;
vector<int> tree[4*N];
int a[N];
int kprv[N];
int cnt[N];
int n;

vector<deque<int>> ids(N);

void build(int id = 0, int ns = 0, int ne = n-1) {
    if (ns == ne) {
        tree[id].push_back(kprv[ns]);
        return;
    }
    int md = (ns+ne)/2;
    int l = 2*id+1;
    int r = 2*id+2;
    build(l, ns, md);
    build(r, md+1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

int get(int qs, int qe, int k, int id = 0, int ns = 0, int ne = n-1) {
    if (qs > ne || qe < ns)
        return 0;
    if (ns >= qs && ne <= qe) {
        return upper_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin();
    }
    int md = (ns+ne)/2;
    int l = 2*id+1;
    int r = 2*id+2;
    int n1 = get(qs, qe, k, l, ns, md);
    int n2 = get(qs, qe, k, r, md+1,ne);
    return n1+n2;
}

int main() {
    SaveTime
    int k; cin >> n >> k;
    memset(kprv, -1, sizeof kprv);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ids[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] > k) {
            kprv[i] = ids[a[i]][0];
            ids[a[i]].pop_front();
        }
    }
    build();
    int last = 0;
    int q; cin >> q;
    while (q--) {
        int a,b; cin >> a >> b;
        a = (a+last)%n+1;
        b = (b+last)%n+1;
        if (a > b)
            swap(a,b);
        last = get(a-1, b-1, a-2);
        cout << last << '\n';
    }
}