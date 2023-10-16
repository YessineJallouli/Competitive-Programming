#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


const int N = 1e5+7;
int fenTree[N];
int tree[4*N], lazy[4*N];
bool marked[4*N];
int a[N];
int n;

void upd(int x, int val) {
    for (; x < N; x+=(x&(-x)))
        fenTree[x] = max(fenTree[x], val);
}

int get(int x) {
    int res = 0;
    for (; x; x-=(x&(-x)))
        res = max(res, fenTree[x]);
    return res;
}

int mrg(int a, int b) {
    return a+b;
}

void unlazy(int id, int ns, int ne) {
    if (marked[id] == 0)
        return;
    tree[id]+= lazy[id]*(ne-ns+1);
    if (ns != ne) {
        int l = 2*id+1;
        int r = 2*id+2;
        lazy[l]+= lazy[id];
        lazy[r]+= lazy[id];
        marked[l] = marked[r] = 1;
    }
    marked[id] = lazy[id] = 0;
}

void updSeg(int qs, int qe, int val, int id = 0, int ns = 0, int ne = n-1) {
    unlazy(id, ns, ne);
    if (ns > qe || ne < qs) {
        return;
    }
    if (ns >= qs && ne <= qe) {
        lazy[id]+= val;
        marked[id] = 1;
        unlazy(id, ns, ne);
        return;
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    updSeg(qs,qe,val,l,ns,md);
    updSeg(qs,qe,val,r,md+1,ne);
    tree[id] = mrg(tree[l], tree[r]);
}

int getSeg(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
    unlazy(id, ns, ne);
    if (ns > qe || ne < qs)
        return 0;
    if (ns >= qs && ne <= qe) {
        return tree[id];
    }
    int l = 2*id+1;
    int r = 2*id+2;
    int md = (ns+ne)/2;
    int n1 = getSeg(qs,qe,l,ns,md);
    int n2 = getSeg(qs,qe,r,md+1,ne);
    return n1 + n2;
}


int main(){
    SaveTime
    cin >>n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    int nb = 0;
    map<int,int> m;
    for (int i : s) {
        m[i] = ++nb;
    }
    for (int i = 0; i < n; i++) {
        a[i] = m[a[i]];
    }
    int ans[n];
    for (int nb = 0; nb < 2; nb++) {
        if (nb == 1) {
            memset(tree, 0, sizeof tree);
            memset(fenTree, 0, sizeof fenTree);
            memset(lazy, 0, sizeof lazy);
            memset(marked, 0, sizeof marked);
        }
        int firstUp[n]; // = {0,1,2,0,0,0,6,6,6,9};
        map<int,int> pos;
        for (int i = 0; i < n; i++) {
            firstUp[i] = get(N-a[i]);
            upd(N-a[i], i+1);
        }
        for (int i = 1; i < n; i++) {
            int id = firstUp[i];
            if (id == 0) {
                updSeg(0, i-1, 1);
            }
            else {
                int md = (id+i+1)/2;
                if (md <= i-1) {
                    updSeg(md, i - 1, 1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nb%2 == 0)
               ans[i] = getSeg(i,i);
            else {
                ans[n-i-1]+= getSeg(i,i);
            }
        }
        reverse(a, a+n);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}