#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct node {
   ll ans, cntL, cntR;
   bool cr;
   node() {
      ans = 1; cntL = 1; cntR = 1; cr = 1;
   }
   node(ll _ans, ll _cntL, ll _cntR, bool _cr) {
      ans = _ans;
      cntL = _cntL;
      cntR = _cntR;
      cr = _cr;
   }
};

const int N = 2e5+7;
node tree[4*N];
int a[N];

ll f(ll nb) {
   return nb*(nb+1)/2;
}

node mrg(node x, node y, int id) {
   node res;
   res.cntL = x.cntL;
   res.cntR = y.cntR;
   res.ans = x.ans + y.ans;
   if (a[id] <= a[id+1]) {
      if (x.cr)
         res.cntL+=y.cntL;
      if (y.cr)
         res.cntR+=x.cntR;
      if (x.cr && y.cr) {
         res.cr = 1;
         res.ans = (f(x.cntL+y.cntL));
      }
      else {
         res.cr = 0;
         res.ans+= x.cntR*y.cntL;
      }
   }
   else
      res.cr = 0;
   return res;
}

int n;

void build(int id = 0, int ns = 0, int ne = n-1) {
   if (ns == ne) {
      tree[id] = node();
      return;
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   build(l, ns, md);
   build(r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r], md);
}

void update(int pos, int val, int id = 0, int ns = 0, int ne = n-1) {
   if (pos < ns || pos > ne)
      return;
   if (ns == ne) {
      a[ns] = val;
      return;
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   update(pos, val, l, ns, md);
   update(pos, val, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r], md);
}

node query(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
   if (qs > ne || qe < ns)
      return node(0,0,0,0);
   if (ns >= qs && ne <= qe)
      return tree[id];
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   node x = query(qs, qe, l, ns, md);
   node y = query(qs, qe, r, md+1, ne);
   return mrg(x,y, md);
}

int main() {
   SaveTime
   int q; cin >> n >> q;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   build();
   while (q--) {
      int t, a,b;
      cin >> t >> a >> b;
      if (t == 2) {
         cout << query(--a, --b).ans << '\n';
      }
      else {
         update(--a, b);
      }
   }
}