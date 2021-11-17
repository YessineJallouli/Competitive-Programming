//https://www.spoj.com/problems/BRCKTS/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 3e4+7;
ll tree[4*N], lazy[4*N], a[N];
bool marked[4*N];

int n;

ll mrg(ll a, ll b) {
   return min(a,b);
}

void build(int id = 0, int ns = 0, int ne = n-1) {
   if (ns == ne) {
      tree[id] = a[ns];
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   build(l, ns, md);
   build(r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

void unlazy(int id, int ns, int ne) {
   if (marked[id] == 0)
      return;
   tree[id]+= lazy[id];
   if (ns != ne) {
      int l = 2*id+1;
      int r = 2*id+2;
      lazy[l] += lazy[id];
      lazy[r] += lazy[id];
      marked[l] = marked[r] = 1;
   }
   marked[id] = 0;
   lazy[id] = 0;
}

void upd(int qs, int qe, int val, int id = 0, int ns = 0, int ne = n-1) {
   unlazy(id, ns,ne);
   if (ns > qe || ne < qs) {
      return;
   }
   if (ns >= qs && ne <= qe) {
      lazy[id] = val;
      marked[id] = 1;
      unlazy(id,ns,ne);
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   upd(qs, qe, val, l, ns, md);
   upd(qs, qe, val, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

ll get(int qs,int qe, int id = 0, int ns = 0, int ne = n-1) {
   unlazy(id, ns, ne);
   if (ns > qe || ne < qs) {
      return INT_MAX; //not necessary zero
   }
   if (ns >= qs && ne <= qe)
      return tree[id];
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

int main() {
   SaveTime
   for (int ii = 1; ii <= 10; ii++) {
      memset(tree, 0, sizeof tree);
      memset(marked, 0, sizeof marked);
      memset(lazy, 0, sizeof lazy);
      cout << "Test " << ii << ":\n";
      cin >> n;
      string s; cin >> s;
      for (int i = 0; i < n; i++) {
         int ad;
         if (s[i] == ')')
            ad = -1;
         else
            ad = 1;
         if (i == 0)
            a[i] = ad;
         else
            a[i] = a[i-1]+ad;
      }
      build();
      int df = a[n-1];
      int m; cin >> m;
      while (m--) {
         int id; cin >> id;
         if (id == 0) {
            if (df == 0 && get(0,n-1) == 0) {
               cout << "YES\n";
            }
            else {
               cout << "NO\n";
            }
         }
         else {
            id--;
            if (s[id] == ')') {
               df+= 2;
               s[id] = '(';
               upd(id, n-1, 2);
            }
            else{
               df-= 2;
               s[id] = ')';
               upd(id, n-1, -2);
            }
         }
      }
   }
}
