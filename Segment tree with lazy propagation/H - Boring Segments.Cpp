//https://codeforces.com/problemset/problem/1555/E
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e6+7;
ll tree[4*N], lazy[4*N];
bool marked[4*N];

int n,m;

ll mrg(ll a, ll b) {
   return min(a,b);
}

void unlazy(int id, int ns, int ne) {
   if (marked[id] == 0)
      return;
   tree[id] = lazy[id];
   if (ns != ne) {
      int l = 2*id+1;
      int r = 2*id+2;
      lazy[l] = lazy[id];
      lazy[r] = lazy[id];
      marked[l] = marked[r] = 1;
   }
   marked[id] = 0;
   lazy[id] = 0;
}

void upd(int qs, int qe, int val, int id = 0, int ns = 1, int ne = m-1) {
   unlazy(id, ns,ne);
   if (ns > qe || ne < qs) {
      return;
   }
   if (ns >= qs && ne <= qe) {
      lazy[id] = val;
      marked[id] = 1;
      unlazy(id,ns,ne);
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   upd(qs, qe, val, l, ns, md);
   upd(qs, qe, val, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}


int main() {
   SaveTime
   cin >> n >> m;
   vector<tuple<int,int,int>> v;
   for (int i = 0; i < n; i++) {
      int a,b,c; cin >> a >> b >> c;
      v.push_back({c,a,b});
   }
   sort(v.begin(), v.end());
   for (int i = 0; i <= 4*m; i++) {
      tree[i] = -1;
   }
   int ans = 1e6;
   for (auto i : v) {
      int w = get<0>(i), l = get<1>(i), r = get<2>(i)-1;
      upd(l,r,w);
      unlazy(0, 1, m);
      if (tree[0] != -1) {
         ans = min(ans*1LL, w-tree[0]);
      }
   }
   cout << ans;
}
