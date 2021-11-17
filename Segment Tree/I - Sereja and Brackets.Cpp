//https://codeforces.com/problemset/problem/380/C
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct node {
   int ans, op, cl;
   node() {
      ans = 0; op = 0; cl = 0;
   }
   node(int _ans, int _op, int _cl) {
      ans = _ans;
      op = _op;
      cl = _cl;
   }
};

const int N = 1e6;
node tree[4*N];
string br;

int n;

node mrg(node x, node y) {
   node res;
   int t = min(x.op, y.cl);
   res.ans = x.ans + y.ans + t;
   res.op = x.op + y.op - t;
   res.cl = x.cl + y.cl - t;
   return res;
}

void build(int id = 0, int ns = 0, int ne = n-1) {
   if (ns == ne) {
      tree[id] = node(0, br[ns] == '(', br[ns] == ')');
      return;
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   build(l, ns, md);
   build(r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

node query(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
   if (ns > qe || ne < qs)
      return node();
   if (ns >= qs && ne <= qe)
      return tree[id];
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   node n1 = query(qs, qe, l, ns, md);
   node n2 = query(qs, qe, r, md+1, ne);
   return mrg(n1, n2);
}

int main() {
   SaveTime
   cin >> br;
   n = br.size();
   build();
   int q; cin >> q;
   while (q--) {
      int a,b; cin >> a >> b;
      cout << query(--a, --b).ans*2 << '\n';
   }
}
