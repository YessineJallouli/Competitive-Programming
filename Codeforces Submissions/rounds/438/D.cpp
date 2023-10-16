#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct node {
   ll sum, mx;
   node() {
      sum = 0; mx = -1;
   }
   node(ll _sum, ll _mx) {
      sum = _sum;
      mx = _mx;
   }
};

node mrg(node x, node y) {
   node res;
   res.sum = x.sum + y.sum;
   res.mx = max(x.mx, y.mx);
   return res;
}

const int N = 1e5+7;

node tree[4*N];
int a[N];

int n;

void build(int id = 0, int ns = 0, int ne = n-1) {
   if (ns == ne) {
      tree[id] = node(a[ns], a[ns]);
      return;
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   build(l, ns, md);
   build(r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

void upd1(int qs, int qe, int val, int id = 0, int ns = 0, int ne = n-1) {
   if (qs > ne || qe < ns)
      return;
   if (ns >= qs && ne <= qe && tree[id].mx < val) {
      return;
   }
   if (ns == ne) {
      tree[id] = node(tree[id].sum%val, tree[id].sum%val);
      return;
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   upd1(qs, qe, val, l, ns, md);
   upd1(qs, qe, val, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

void upd2(int pos, int val, int id = 0, int ns = 0, int ne = n-1) {
   if (pos < ns || pos > ne)
      return;
   if (ns == ne) {
      tree[id] = node(val, val);
      return;
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   upd2(pos, val, l, ns, md);
   upd2(pos, val, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

node query(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
   if (qs > ne || qe < ns)
      return node();
   if (ns >= qs && ne <= qe) {
      return tree[id];
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   node n1 = query(qs, qe, l, ns, md);
   node n2 = query(qs, qe, r, md+1, ne);
   return mrg(n1, n2);
}


int main() {
   SaveTime
   int m; cin >> n >> m;
   for (int i = 0; i < n; i++)
      cin >> a[i];
   build();
   while (m--) {
      int t; cin >> t;
      if (t == 1) {
         int a,b; cin >> a >> b;
         cout << query(--a, --b).sum << '\n';
      }
      else if (t == 2) {
         int a,b,c; cin >> a >> b >> c;
         upd1(--a, --b, c);
      }
      else {
         int a,b; cin >> a >> b;
         upd2(--a, b);
      }
   }
}