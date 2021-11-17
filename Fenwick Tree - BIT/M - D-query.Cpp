//https://www.spoj.com/problems/DQUERY/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 3e4+7;
const int mx = 1e6+7;
const int mxQ = 2e5+7;
int a[N], tree[N];
int ans[mxQ];
int lastS[mx];
int n;
vector<tuple<int,int,int>> query;

void upd(int x, int val) {
   for (; x <= n; x+=x&(-x))
      tree[x]+= val;
}

int get(int x) {
   int res = 0;
   for (; x; x-=x&(-x))
      res+= tree[x];
   return res;
}

int main() {
   /// Offline solution ?
   cin >> n;
   for (int i = 1; i <= n; i++)
      cin >> a[i];
   int Q; cin >> Q;
   for (int i = 0; i < Q; i++) {
      int a,b; cin >> a >> b;
      query.push_back({b,a,i});
   }
   sort(query.begin(), query.end());
   int id = 0;
   memset(lastS, -1, sizeof lastS);
   for (int i = 1; i <= n; i++) {
      if (lastS[a[i]] != -1) {
         upd(lastS[a[i]], -1);
      }
      lastS[a[i]] = i;
      upd(i, 1);
      while (id < Q && get<0>(query[id]) == i) {
         int b = get<0>(query[id]), a = get<1>(query[id]), pos = get<2>(query[id]);
         ans[pos] = get(b) - get(a-1);
         id++;
      }
   }
   for (int i = 0; i < Q; i++)
      cout << ans[i] << '\n';
}
