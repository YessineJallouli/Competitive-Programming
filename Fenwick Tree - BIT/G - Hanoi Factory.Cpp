//https://codeforces.com/problemset/problem/777/E
//Solved with segment tree
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 2e5+7;
int a[N],b[N],h[N];
ll tree[4*N];
ll ans[N];
int n;
vector<set<int>> s1(N);

void upd(int pos, ll val, int id = 0, int ns = 0, int ne = N-1) {
   if (pos > ne || pos < ns)
      return;
   if (ns == ne) {
      tree[id] = val;
      return;
   }
   int md = (ne+ns)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   upd(pos, val, l, ns, md);
   upd(pos, val, r, md+1, ne);
   tree[id] = max(tree[r], tree[l]);
}

ll get(int qs, int qe, int id = 0, int ns = 0, int ne = N-1) {
   if (qs > ne || qe < ns) {
      return 0LL;
   }
   if (ns >= qs && ne <= qe)
      return tree[id];
   int md = (ne+ns)/2;
   int l = 2*id+1;
   int r = 2*id+2;
   ll n1 = get(qs, qe,l, ns, md);
   ll n2 = get(qs, qe,r, md+1,ne);
   return max(n1, n2);
}


int main() {
   SaveTime
   cin >> n;
   set<int> s;
   for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i] >> h[i];
      s.insert(a[i]);
      s.insert(b[i]);
   }
   /// compression
   int nb = 1;
   map<int,int> comp;
   for (int i : s)
      comp[i] = nb++;
   for (int i = 0; i < n; i++) {
      a[i] = comp[a[i]];
      b[i] = comp[b[i]];
   }
   vector<tuple<int,int,int>> v;
   for (int i = 0; i < n; i++) {
      v.push_back({b[i], a[i], h[i]});
   }
   sort(v.begin(), v.end());
   for (int i = 0; i < n; i++) {
      int x = get<1>(v[i]), y = get<0>(v[i]), z = get<2>(v[i]);
      a[i] = x, b[i] = y, h[i] = z;
   }
   ll res = 0;
   for (int i = 0; i < n; i++) {
      ans[i] = h[i] + get(a[i]+1, N-1);
      upd(b[i], ans[i]);
      res = max(res, ans[i]);
   }
   cout << res;
}
