#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


const int N = 4e5+7;
int a[N], b[N];
int tree[N], ans[N];
int n;

int get(int x) {
   int res = 0;
   for (; x; x-=x&(-x))
      res+= tree[x];
   return res;
}

void upd(int x, int val) {
   for (; x < N; x+=x&(-x))
      tree[x]+= val;
}


int main() {
   SaveTime
   /// compress and sort
   set<int> s;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      s.insert(a[i]);
      s.insert(b[i]);
   }
   map<int,int> m;
   int nb = 1;
   for (int i : s)
      m[i] = nb++;
   vector<tuple<int,int,int>> v;
   for (int i = 0; i < n; i++) {
      a[i] = m[a[i]];
      b[i] = m[b[i]];
      v.push_back({b[i], a[i], i});
   }
   sort(v.begin(), v.end());
   for (int i = 0; i <n; i++) {
      int x = get<0>(v[i]), y = get<1>(v[i]), z = get<2>(v[i]);
      ans[z] = get(x) - get(y-1);
      upd(y, 1);
   }
   for (int i = 0; i < n; ++i)
      cout << ans[i] << '\n';
}