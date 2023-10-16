#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;
vector<int> tree[N];
int ty[N],t[N],a[N];

set<int> s1[N];
set<int> s2;
map<int,int> codage1;
vector<pair<int,int>> cd[N];

int n;

void upd(int num, int tim, int val) {
   for (; tim < (int) tree[num].size(); tim+= tim&(-tim))
      tree[num][tim]+= val;
}

int get(int num, int tim) {
   int res = 0;
   for (; tim; tim-=tim&(-tim))
      res+= tree[num][tim];
   return res;
}

int main() {
   /// compression ?
   SaveTime
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> ty[i] >> t[i] >> a[i];
   }
   int nb = 1;
   for (int i = 0; i < n; i++) {
      if (codage1[a[i]] == 0)
         codage1[a[i]] = nb++;
      a[i] = codage1[a[i]];
      s2.insert(a[i]);
   }
   for (int i = 0; i < n; i++) {
      s1[a[i]].insert(t[i]);
   }
   for (int i = 0; i < n; i++) {
      tree[a[i]].resize(s1[a[i]].size()+2, 0);
   }
   for (int i = 0; i < n; i++) {
      cd[a[i]].push_back({t[i], i});
   }
   for (int i : s2)
      sort(cd[i].begin(), cd[i].end());
   for (int i = 0; i < N; i++) {
      int nb = 1;
      for (auto h : cd[i]) {
         int y = h.second;
         t[y] = nb++;
      }
   }
   for (int i = 0; i < n; i++) {
      if (ty[i] == 1) {
         upd(a[i], t[i], 1);
      }
      else if (ty[i] == 2) {
         upd(a[i], t[i], -1);
      }
      else {
         cout << get(a[i], t[i]) << '\n';
      }
   }
}