//https://www.codechef.com/problems/DIVMAC
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e6+7;

int sieve[N];
int tree[4*N];
int a[N];

int n;

int mrg(int a, int b) {
   return max(a,b);
}

void build(int id = 0, int ns = 0, int ne = n-1) {
   if (ns == ne) {
      tree[id] = sieve[a[ns]];
      return;
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   build(l, ns, md);
   build(r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

void upd(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
   if (qs > ne || qe < ns)
      return;
   if (ns >= qs && ne <= qe && tree[id] == 1) {
      return;
   }
   if (ns == ne) {
      if (a[ns] == 1)
         return;
      a[ns]/= sieve[a[ns]];
      tree[id] = sieve[a[ns]];
      return;
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   upd(qs, qe, l, ns, md);
   upd(qs, qe, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

int query(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
   if (qs > ne || qe < ns)
      return -1;
   if (ns >= qs && ne <= qe) {
      return tree[id];
   }
   int md = (ns+ne)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   int n1 = query(qs, qe, l, ns, md);
   int n2 = query(qs, qe, r, md+1, ne);
   return mrg(n1, n2);
}

int main() {
   SaveTime
   memset(sieve, -1, sizeof sieve);
   sieve[1] = 1;
   for (int i = 2; i < N; i++) {
      if (sieve[i] == -1) {
         for (int j = i; j < N; j+= i) {
            if (sieve[j] == -1)
               sieve[j] = i;
         }
      }
   }
   int T; cin >> T;
   while (T--) {
      int m; cin >> n >> m;
      for (int i = 0; i < n; i++)
         cin >> a[i];
      build();
      while (m--) {
         int a,b,c; cin >> a >> b >> c;
         if (a == 0) {
            upd(--b, --c);
         }
         else {
            cout << query(--b, --c) << ' ';
         }
      }
      cout << '\n';
   }
}
