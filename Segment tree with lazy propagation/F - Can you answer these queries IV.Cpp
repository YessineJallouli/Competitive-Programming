//https://www.spoj.com/problems/GSS4/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;

ll tree[4*N], mx[4*N], a[N];
int n;

ll mrg(ll a, ll b) {
   return a+b;
}

bool isPrime(ll n) {
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
      tree[id] = a[ns];
      mx[id] = a[ns];
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   build(l, ns, md);
   build(r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
   mx[id] = max(mx[l], mx[r]);
}

void upd(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
   if (ns > qe || ne < qs)
      return;
   if (mx[id] == 1)
      return;
   if (ns == ne) {
      tree[id] = sqrt(tree[id]);
      mx[id] = sqrt(mx[id]);
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   upd(qs, qe, l, ns, md);
   upd(qs, qe, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
   mx[id] = max(mx[l],mx[r]);
}

ll get(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
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
   int nb = 1;
   while(cin >> n) {
      cout << "Case #" << nb << ":\n";
      for (int i = 0; i < n; i++)
         cin >> a[i];
      build();
      int q; cin >> q;
      while (q--) {
         int t; cin >> t;
         int a,b; cin >> a >> b;
         if (a > b)
            swap(a,b);
         if (t == 0) {
            upd(--a, --b);
         }
         else {
            cout << get(--a, --b) << '\n';
         }
      }
      nb++;
   }
}
