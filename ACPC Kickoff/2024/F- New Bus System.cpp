#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3+7; // n max
int tree[4*N];

int mrg(int x, int y) {
    return max(x,y);
}

int get(int qs, int qe, int id = 0, int ns = 0, int ne = N-1) {
    if (ns > qe || ne < qs) {
        return 0; // 0 for sum/gcd/or/xor and 1 for and/product and infinity for max/min
    }
    if (qs <= ns && qe >= ne) {
        return tree[id];
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

void upd(int pos, int val, int id = 0, int ns = 0, int ne = N-1) {
    if (pos > ne || pos < ns)
        return;
    if (ns == ne) {
        tree[id] = val;
        return;
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    upd(pos, val, l, ns, md);
    upd(pos, val ,r, md+1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            if (x == 1) {
                p.push_back(j);
            }
        }
    }
    n = (int) p.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mx = get(p[i]+1, N-1) + 1;
        int myDp = get(p[i], p[i]);
        upd(p[i], max(mx, myDp));
    }
    for (int i = 0; i < N; i++) {
        ans = max(ans, get(i,i));
    }
    cout << ans;
}
