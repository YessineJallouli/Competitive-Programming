//https://www.spoj.com/problems/SEGSQRSS/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 2e5+7;

ll tree[4*N], lazy1[4*N], lazy2[4*N], a[N], lastLazy[4*N], sum[4*N], b[N];
bool marked[4*N];
int n;

ll mrg(ll a, ll b) {
   return a+b;
}

void build(int id = 0, int ns = 0, int ne = n-1) {
   if (ns == ne) {
      tree[id] = a[ns];
      sum[id] = b[ns];
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   build(l, ns, md);
   build(r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
   sum[id] = mrg(sum[l], sum[r]);
}

void unlazy(int id, int ns, int ne) {
   if (marked[id] == 0)
      return;
   if (lastLazy[id] == 0) {
      sum[id] = lazy1[id]*(ne-ns+1);
      tree[id] = lazy1[id] * (lazy1[id] * (ne-ns+1));
   }
   else {
      tree[id] += lazy2[id]*lazy2[id]*(ne-ns+1) + 2*lazy2[id] * sum[id];
      sum[id]+= (lazy2[id]*(ne-ns+1));
   }
   if (ns != ne) {
      int l = 2*id+1;
      int r = 2*id+2;
      int md = (ns+ne)/2;
      if (lastLazy[id] == 0) {
         lazy1[l] = lazy1[r] = lazy1[id];
         lazy2[l] = lazy2[r] = 0;
      }
      else {
         lazy2[l]+= lazy2[id];
         lazy2[r]+= lazy2[id];
      }
      marked[l] = marked[r] = 1;
      lastLazy[l] = lastLazy[r] = lastLazy[id];
   }
   lazy1[id] = lazy2[id] = 0;
   marked[id] = 0;
}

void upd(int qs, int qe, int v, int type, int id = 0, int ns = 0, int ne = n-1) {
   unlazy(id, ns, ne);
   if (ns > qe || ne < qs)
      return;
   if (ns >= qs && ne <= qe) {
      marked[id] = 1;
      lastLazy[id] = type;
      if (type == 0) {
         lazy1[id] = v;
         lazy2[id] = 0;
      }
      else {
         lazy2[id] += v;
      }
      unlazy(id, ns, ne);
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   upd(qs, qe, v, type, l, ns, md);
   upd(qs, qe, v, type, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

ll getSquareSum(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
   unlazy(id, ns, ne);
   if (ns > qe || ne < qs)
      return 0;
   if (ns >= qs && ne <= qe) {
      return tree[id];
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   ll ln = getSquareSum(qs, qe, l, ns, md);
   ll rn = getSquareSum(qs, qe, r, md+1, ne);
   return mrg(ln, rn);
}


int main() {
   SaveTime
   int T; cin >> T;
   for (int ii = 1; ii <= T; ii++) {
      cout << "Case " << ii << ":\n";
      int q; cin >> n >> q;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         b[i] = a[i];
         a[i]*= a[i];
      }
      build();
      memset(lazy1, 0, sizeof lazy1);
      memset(lazy2, 0, sizeof lazy2);
      memset(marked, 0, sizeof marked);
      while (q--) {
         int type; cin >> type;
         if (type != 2) {
            int a,b,c; cin >> a >> b >> c;
            if (a > b)
               swap(a,b);
            upd(--a,--b,c,type);
         }
         else {
            int a,b; cin >> a >> b;
            if (a > b)
               swap(a,b);
            cout << getSquareSum(--a,--b) << '\n';
         }
      }
   }
   //char c; cin >> c;
}
