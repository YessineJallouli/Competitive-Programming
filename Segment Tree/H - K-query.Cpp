//https://www.spoj.com/problems/KQUERY/en/
#include <bits/stdc++.h>
using namespace std;

int inf = 1e9;

const int N = 3e4+7; // n max
int n;

int a[N], tree[4*N];

int mrg(int x, int y) {
   return x+y;
}

int get(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
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

void upd(int pos, int val, int id = 0, int ns = 0, int ne = n-1) {
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

int main() {
   cin >> n;
   memset(tree, 0, sizeof tree);
   vector<tuple<int,int,int,int>> v;
   for (int i = 0; i < n; i++) {
      int x; cin >> x;
      v.push_back({-x,inf, i,i});
   }
   int q; cin >> q;
   for (int i = 0; i < q; i++) {
      int a,b,c; cin >> a >> b >> c;
      v.push_back({-c,i,a,b});
   }
   sort(v.begin(), v.end());
   int ans[q];
   for (int i = 0; i < v.size(); i++) {
      int l = get<2>(v[i]), r = get<3>(v[i]), id = get<1>(v[i]), k = -get<0>(v[i]);
      if (id != inf) {
         ans[id] = get(--l, --r);
      }
      else {
         upd(l, 1);
      }
   }
   for (int i = 0; i < q; i++) {
      cout << ans[i] << '\n';
   }
}
