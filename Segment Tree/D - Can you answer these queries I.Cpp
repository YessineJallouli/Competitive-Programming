//https://www.spoj.com/problems/GSS1/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct node {
   ll ans,pr,sf,sum;
   node() {
      ans = -1e9;
      pr = sf = sum = 0LL;
   }
   node(ll _ans, ll _pr, ll _sf, ll _sum) {
      ans = _ans;
      pr = _pr;
      sf = _sf;
      sum = _sum;
   }
};

const int N = 2e5+7;
node tree[4*N];
int a[N];
int n;

node mrg(node x, node y) {
   node res;
   res.ans = max({x.ans, y.ans, x.sf + y.pr});
   res.pr = max({x.pr, x.sum + y.pr});
   res.sf = max(y.sf, y.sum + x.sf);
   res.sum = x.sum+y.sum;
   return res;
}

void build(int id = 0, int ns = 0, int ne = n-1) {
   if (ns == ne) {
      tree[id] = node(a[ns], a[ns], a[ns], a[ns]);
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
   if (qs > ne || qe < ns)
      return node(-1e9, -1e9, -1e9, 0);
   if (ns >= qs && ne <= qe)
      return tree[id];
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   node x = query(qs, qe, l, ns, md);
   node y = query(qs, qe, r, md+1, ne);
   return mrg(x,y);
}

int main() {
   SaveTime
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   build();
   int q; cin >> q;
   while (q--) {
      int a,b;
      cin >> a >> b;
      cout << query(--a, --b).ans << '\n';
   }
}
