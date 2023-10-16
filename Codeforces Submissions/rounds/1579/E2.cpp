#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

const int N = 3e5+2; // n max
ll a[N], tree[4*N];

ll mrg(ll x, ll y) {
   return x+y;
}

void upd(int pos, int val, int id = 0, int ns = 0, int ne = N-1) {
   if (pos > ne || pos < ns)
      return;
   if (ns == ne) {
      tree[id] += val;
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   upd(pos, val, l, ns, md);
   upd(pos, val ,r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

ll get(int qs, int qe, int id = 0, int ns = 0, int ne = N-1) {
   if (ns > qe || ne < qs) {
      return 0; // 0 for sum/gcd/or/xor and 1 for and/product and infinity for max/min
   }
   if (qs <= ns && qe >= ne) {
      return tree[id];
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   return mrg(get(qs, qe, l, ns, md), get(qs, qe, r, md+1, ne));
}

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      ll ans = 0;
      map<int,int> m;
      set<int> s;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         s.insert(a[i]);
      }
      int nb = 1;
      for (int i : s) {
         m[i] = nb++;
      }
      for (int i = 0; i < n; i++) {
         a[i] = m[a[i]];
      }
      for (int i = 0; i < n; i++) {
         int x = a[i];
         int nb1 = get(0, a[i]-1);
         int nb2 = get(a[i]+1, N-1);
         ans+= min(nb1, nb2);
         upd(a[i], 1);
      }
      for (int i = 0; i < n; i++) {
         upd(a[i], -1);
      }
      cout << ans << '\n';
   }
}