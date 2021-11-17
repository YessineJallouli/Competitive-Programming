//https://www.spoj.com/problems/INVCNT/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios::sync_with_stdio(0); cout.tie(0);
using namespace std;

const int N = 1e7 + 7;
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

int n;
int a[N];

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      cin >> n;
      ll ans = 0;
      for (int i = 0; i < n; i++)
         cin >> a[i];
      for (int i = n-1; i >= 0; i--) {
         upd(a[i], 1);
         ans += get(a[i]-1);
      }
      for (int i = 0; i < n; i++) {
         upd(a[i], -1);
      }
      cout << ans << '\n';
   }
}
