//
// Created by yessine on 6/6/23.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+2;
int n;
int tree[4*N];

int mrg(int x, int y) {
    return x+y;
}

int get(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
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

void upd(int pos, int val, int id = 0, int ns = 0, int ne = n-1) {
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
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string a,b; cin >> a >> b;
        n = (int) a.size();
        for (int i = 0; i < 4*n; i++)
            tree[i] = 0;
        int q,t; cin >> t >> q;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                upd(i, 1);
        }
        int time = 0;
        deque<pair<int,int>> queue;
        set<int> blocked;
        while (q--) {
            time++;
            while (! queue.empty() && time >= queue[0].first) {
                int pos = queue[0].second;
                upd(pos, (a[pos] == b[pos]));
                queue.pop_front();
                blocked.erase(pos);
            }
            int type; cin >> type;
            if (type == 1) {
                int pos; cin >> pos; pos--;
                blocked.insert(pos);
                upd(pos, 1);
                queue.emplace_back(time+t, pos);
            }
            else if (type == 2) {
                int s1,pos1,s2,pos2; cin >> s1 >> pos1 >> s2 >> pos2;
                pos1--; pos2--;
                if (s1 == 1) {
                    if (s2 == 1)
                        swap(a[pos1], a[pos2]);
                    else
                        swap(a[pos1], b[pos2]);
                }
                else {
                    if (s2 == 1)
                        swap(b[pos1], a[pos2]);
                    else
                        swap(b[pos1], b[pos2]);
                }
                if (! blocked.count(pos1)) {
                    upd(pos1, (a[pos1] == b[pos1]));
                }
                if (! blocked.count(pos2)) {
                    upd(pos2, (a[pos2] == b[pos2]));
                }
            }
            if (type == 3) {
                if (get(0, n-1) == n) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
    }
}