//https://www.spoj.com/problems/RATING/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios::sync_with_stdio(0); cout.tie(0);
using namespace std;

const int N = 3e5 + 7;
int tree[N];

void upd(int x, int val) {
   for (; x < N; x += x&(-x))
      tree[x]+= val;
}

int get(int x) {
   int res = 0;
   for (; x; x-= x&(-x))
      res+= tree[x];
   return res;
}

int main() {
   int n; cin >> n;
   vector<tuple<int,int,int>> v;
   int x[n], y[n];
   map<pair<int,int>, int> m;
   for (int i = 0; i < n; i++) {
      int a,b; cin >> a >> b;
      x[i] = a, y[i] = b;
      m[{a,b}]++;
      v.push_back({a,b,i});
   }
   sort(v.begin(), v.end());
   int ans[n];
   map<pair<int,int>,int> same;
   for (auto i : v) {
      int a = get<0>(i), b = get<1>(i), c = get<2>(i);
      ans[c] = get(b);
      same[{a,b}] = ans[c];
      upd(b, 1);
   }
   for (int i = 0; i < n; i++) {
      cout << max(same[{x[i], y[i]}], ans[i]) - m[{x[i],y[i]}] +1  << '\n';
   }
}
