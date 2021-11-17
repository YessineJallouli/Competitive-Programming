//https://www.spoj.com/problems/PRMQUER/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;
 
const int N = 2e5+7;
 
ll tree[4*N], lazy1[4*N], lazy2[4*N], a[N], sum[4*N];
bool marked[4*N];
int n;
 
ll mrg(ll a, ll b) {
   return a+b;
}
 
bool isPrime(int n) {
   if (n > 1e7)
      return 0;
   if (n == 1)
      return 0;
   if (n < 4)
      return 1;
   if (n%2 == 0)
      return 0;
   for (int i = 3; i*i <= n; i+= 2) {
      if (n%i == 0)
         return 0;
   }
   return 1;
}
 
void build(int id = 0, int ns = 0, int ne = n-1) {
   if (ns == ne) {
      tree[id] = isPrime(a[ns]);
      sum[id] = a[ns];
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
   tree[id] = lazy1[id] * (ne-ns+1);
   sum[id] = lazy2[id] * (ne-ns+1);
   if (ns != ne) {
      int l = 2*id+1;
      int r = 2*id+2;
      int md = (ns+ne)/2;
      lazy1[l] = lazy1[r] = lazy1[id];
      lazy2[l] = lazy2[r] = lazy2[id];
      marked[l] = marked[r] = 1;
   }
   lazy1[id] = lazy2[id] = 0;
   marked[id] = 0;
}
 
void upd1(int qs, int qe, int v, int id = 0, int ns = 0, int ne = n-1) {
   unlazy(id, ns, ne);
   if (ns > qe || ne < qs)
      return;
   if (ns >= qs && ne <= qe) {
      marked[id] = 1;
      lazy1[id] = isPrime(v);
      lazy2[id] = v;
      unlazy(id, ns, ne);
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   upd1(qs, qe, v, l, ns, md);
   upd1(qs, qe, v, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
   sum[id] = mrg(sum[l], sum[r]);
}
 
void upd2(int pos, int v, int id = 0, int ns = 0, int ne = n-1) {
   unlazy(id, ns, ne);
   if (pos > ne || pos < ns)
      return;
   if (ne == ns) {
      sum[id]+= v;
      tree[id] = isPrime(sum[id]);
      lazy1[id] = lazy2[id] = 0;
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   upd2(pos, v, l, ns, md);
   upd2(pos, v, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
   sum[id] = mrg(sum[l], sum[r]);
}
 
ll get(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
   unlazy(id, ns, ne);
   if (ns > qe || ne < qs)
      return 0;
   if (ns >= qs && ne <= qe) {
      return tree[id];
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   ll ln = get(qs, qe, l, ns, md);
   ll rn = get(qs, qe, r, md+1, ne);
   return mrg(ln, rn);
}
 
int main() {
   SaveTime
   int q; cin >> n >> q;
   for (int i = 0; i <n; i++) {
      cin >> a[i];
   }
   build();
   memset(lazy1, 0, sizeof lazy1);
   memset(lazy2, 0, sizeof lazy2);
   memset(marked, 0, sizeof marked);
   while (q--) {
      char c; cin >> c;
      if (c == 'A') {
         int a,b; cin >> a >> b;
         upd2(--b, a);
      }
      else if (c == 'R') {
         int a,b,c; cin >> a >> b >> c;
         upd1(--b, --c, a);
      }
      else {
         int a,b; cin >> a >> b;
         cout << get(--a,--b) << '\n';
      }
   }
}
